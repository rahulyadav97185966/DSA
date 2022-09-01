#include<bits/stdc++.h>
using namespace std;
class node{
    public:
      int data;
      node* left;
      node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node*  root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data  == -1){
        return NULL;
    }

    cout<<"Enter the data to insert into the left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to insert into the right "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
int findheight(node* root){
    if(root == NULL){
        return 0;
    }
    return findheight(root->left)+1;
}
bool sameLevel(node* root, int height, int h){
    if(root == NULL)return true;
    if(root->left == NULL && root->right == NULL){
        if(h != height){
            return false;
        }
    }
    return sameLevel(root->left, height, h+1);
    return sameLevel(root->right, height, h+1);
}
int main(){
    node* root = NULL;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    root = buildTree(root);

    //level order traversal
    int height = findheight(root);
    cout<<height<<" ";
    cout<<"The Tree is same leve : "<<sameLevel(root, height, 1);
    return 0;
}