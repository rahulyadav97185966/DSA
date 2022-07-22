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
pair<int,int> predAndSucc(Node* root, int key){
    if(root == NULL){
        return {0, 0};
    }
    int pred = -1;
    int succ = -1;

    while(root->data != key){
        if(root->data >= key){
            pred = root->data;
            root = root->left;
        }
        else{
            succ = root->data;
            root = root->right;
        }
    }

    //find predecessor
    Node* lefttree = root->left;
    while(lefttree != NULL){
        pred = lefttree->data;
        lefttree = lefttree->right;
    } 
    //successor
    Node* righttree = root->right;
    while(righttree != NULL){
        succ = righttree->data;
        righttree = righttree->left;
    }
    pair<int, int> ans;
    ans.first = pred;
    ans.second = succ;
    return ans;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    cout<<"predecessor  of the  key is  "<<predAndSucc(root, 6).first;
    cout<<"successor of the key is using "<<predAndSucc(root, 3).second;
    return 0;
}