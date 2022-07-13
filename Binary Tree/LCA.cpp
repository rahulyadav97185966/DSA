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
    cout<<"Enter the data"<<endl;
    int d;
    cin>>d;
    root = new Node(d);

    if(d == -1){
        return NULL;
    }
    cout<<"Enter the value of the left "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value of the right "<<d<<endl;
    root->right = buildTree(root->right);
}
Node* LCA(Node* root, int node1, int node2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == node1 || root->data == node2){
        return root;
    }
    Node* leftAns = LCA(root->left, node1, node2);
    Node* rightAns = LCA(root->right, node1, node2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return leftAns;
    }
    else{
        return NULL;
    }

}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    Node* d = LCA(root, 3, 4);
    cout<<"LCA of the two nodes is"<<d->data;
    
    return 0;
}
