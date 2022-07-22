#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
//Lever Order Traversal Uses Queue
void leverOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        //insert to right
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = insertIntoBST(root, d);
        cin>>d;
    }
}
int Smallest(Node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }
    //left
    int left = Smallest(root->left, i, k);
    if(left != -1){
        return left;
    }
    //N
    i++;
    if(i == k){
        return root->data;
    }
    //r
    return Smallest(root->right, i,k);
}
//using morris Traversal
int SmallestMorris(Node* root, int &j, int k){
    if(root == NULL){
        return -1;
    }
    Node* current = root;
    while(current){
        if(current->left == NULL){
            j++;
            if(j == k){
                return current->data;
            }
            current = current->right;
        }
        else{
            Node* pred = current->left;
            while(pred->right && pred->right != current){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = current;
                current = current->left;
            }
            else{
                pred->right = NULL;
                j++;
                if(j == k){
                    return current->data;
                }    
                current = current->right;
            }
        }
    }
    return -1;
}
int main(){
    //5 4 8 2 6 10 3 7 -1
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    int i = 0;   
    int j = 0;
    cout<<"kth Smallest is "<<Smallest(root, i, 3);
    cout<<"\nkth Smallest using morris is "<<SmallestMorris(root, j, 3);
    return 0;
}