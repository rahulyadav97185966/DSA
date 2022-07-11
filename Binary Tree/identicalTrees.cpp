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
bool isIdentical(Node* p, Node* q){
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL && q != NULL)
        return false;
    if(p != NULL && q == NULL)
        return false;
    bool leftAns = isIdentical(p->left, q->left);
    bool rightAns = isIdentical(p->right, q->right);
    bool currentNode = p->data == q->data;
    return (leftAns && rightAns && currentNode);
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    Node* root2 = NULL;
    root = buildTree(root2);
    cout<<"the trees are "<<isIdentical(root, root2);

    return 0;
}
