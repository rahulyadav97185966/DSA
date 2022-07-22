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
bool SearchTree(Node* root, int target){
     // base condition
     if(root == NULL){
        return false;
     }
     if(root->data == target){
        return true;
     }
     if(target < root->data){
        return SearchTree(root->left, target);
     }
     else{
        return SearchTree(root->right, target);
    }   
}   
//Using while loop
bool SearchTreeWhile(Node* root, int target){
    Node* temp = root;
    while(!temp){
        if(temp->data == target){
            return true;
        }
        if(target < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        } 
    }
    return false;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    cout<<"Search the node in BST is "<<SearchTree(root, 40);
    cout<<"\nSearch the node in BST using while loop is "<<SearchTree(root, 40);
    return 0;
}