#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        //Costructor for creating the node
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* buildTree(Node* root){
    int val;
    cout<<"Enter the data \n";
    cin>>val;
    root = new Node(val);

    if(val == -1){
        return NULL;
    }
    cout<<"Enter the data to insert into the left \n"<<val<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to insert into the right \n"<<val<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    cout<<"\n Level Order Traversal of the tree is "<<endl;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){

    Node* root = NULL;
    // 1 2 3 -1 -1 4 -1 -1 5 -1 -1
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}