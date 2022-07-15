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
//preorder follows NLR (node, left, right)
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//Iterative preorder Traversal (Node, left, right)
//For iterative way we need to use stack and push the root and till the stack is not emptyy we need to pop if right is present thenn again insert into it we need to insert right first cause we need to proceess the left tree first
void preOrderIterative(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* front = st.top();
        st.pop();
        cout<<front->data<<" ";
        if(front->right){
            st.push(front->right);
        }
        if(front->left){
            st.push(front->left);
        }
    }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
     // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    cout<<"Preorder traversal of the tree is "<<endl;
    preOrder(root);
    cout<<"\nPreorder traversal of the tree is Iteratively "<<endl;
    preOrderIterative(root);
    return 0;
}