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

//postorder traversal follows left, right and Node (LRN);
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//Iterative postorder Traversal
void postOrderTraversal(Node* root){
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* front = st1.top();
        st1.pop();
        st2.push(front);
        if(front->left){
            st1.push(front->left);
        }
        if(front->right){
            st1.push(front->right);
        }
    }
    while(!st2.empty()){
        Node* topNode = st2.top();
        st2.pop();
        cout<<topNode->data<<" ";
    }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    cout<<"Preorder traversal of the tree is "<<endl;
    postOrder(root);
    cout<<"\nPreorder traversal of the tree Iteratively is "<<endl;
    postOrderTraversal(root);
    return 0;
}