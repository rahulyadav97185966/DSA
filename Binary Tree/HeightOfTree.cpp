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

int HeightOfTree(Node* root){
    if(root == NULL)
        return 0;
    
    int leftHeight = HeightOfTree(root->left);
    int rightHeight = HeightOfTree(root->right);

    return max(leftHeight, rightHeight)+1;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"Preorder traversal of the tree is "<<endl;
    cout<<"Height of the Tree is"<<HeightOfTree(root)<<endl;
    return 0;
}