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
//inorder follows NLR (node, left, right)
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
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
//postorder traversal follows left, right and Node (LRN);
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//Lever Order Traversal Uses Queue
void leverOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}
int main(){
    Node* root = NULL;
    // 4 2 1 -1 -1 3 8 -1 -1 -1  -1 10 7 -1 -1 -1
    root = buildTree(root);
    cout<<"Preorder traversal of the tree is "<<endl;
    preOrder(root);
    cout<<"\ninOrder traversal of the tree is "<<endl;
    inOrder(root);
    cout<<"\npostOrder traversal of the tree is "<<endl;
    postOrder(root);
    cout<<"\n everOrderTraversal traversal of the tree is "<<endl;
    leverOrderTraversal(root);

    return 0;
}