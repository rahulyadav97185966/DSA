#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data";
    int d;
    cin>>d;
    root = new Node(d);
    if(d == -1){
        return NULL;
    }
    cout<<"Enter value for left of node "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter value for right of node "<<d<<endl;
    root->right = buildTree(root->right);
}
void FlattenLL(Node* &root){
    if(root == NULL){
        return;
    }
    Node* current = root;
    while(current != NULL){
        if(current->left != NULL){
            Node* pred = current->left;
            while(pred->right){
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL; // we can do this to current->left to null or we can use 45 line
        }
        current = current->right;
    }
    //left part null
    // current = root;
    // while(current != NULL){
    //     current->left = NULL;
    //     current = current->right;
    // }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    FlattenLL(root);
    
    return 0;
}