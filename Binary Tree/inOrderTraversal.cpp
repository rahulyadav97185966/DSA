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
//inorder follows LNR (left, node, right)
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//Iterative inorder traversal
void inOrderIterative(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    cout<<"inorder traversal of the tree is "<<endl;
    inOrder(root);
    cout<<"\ninorder traversal of the tree iteraively is "<<endl;
    inOrderIterative(root);
    return 0;
}