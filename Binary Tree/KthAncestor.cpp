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
Node* kthAncestor(Node* root, int &k, int node){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    Node* leftAns = kthAncestor(root->left, k, node);
    Node* rightAns = kthAncestor(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    int k = 2;
    Node* node1 = kthAncestor(root, k, 4);
    if(node1 == NULL || node1->data == 4){
        cout<<"-1";
    }
    cout<<node1->data<<"\n";

    return 0;
}
