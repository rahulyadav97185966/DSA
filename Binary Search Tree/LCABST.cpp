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
Node* LCA(Node* root, int a, int b){
    //base case
    if(root == nullptr){
        return nullptr;
    }
    if(root->data < a && root->data < b){
        return LCA(root->right, a, b);
    }
    if(root->data > a && root->data > b){
        return LCA(root->left, a, b);
    }
    else{
        return root;
    }

}
//using Iterative also we can do
Node* LCAIterative(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    while(root != NULL){
        //left case
        //right case
        //both on left and right 
        if(root->data > a && root->data > b){
            root = root->right;
        }
        if(root->data < a && root->data < b){
            root = root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    cout<<"THE LCA IS "<<LCA(root, 2, 8)->data;
    cout<<"THE LCA Iteratively is "<<LCA(root, 8, 16)->data;
    return 0;
}