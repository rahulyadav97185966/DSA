#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};
Node* createTree(Node* root){
    cout<<"Enter the data\n";
    int d;
    cin>>d;
    root = new Node(d);

    if(d == -1){
        return NULL;
    }
    cout<<"Enter data for left of"<<d<<endl;
    root->left = createTree(root->left);
    cout<<"Enter data for right of"<<d<<endl;
    root->right = createTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}
int Totalnodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1+Totalnodes(root->left)+Totalnodes(root->right);
    return ans;
}
bool isCBT(Node* root, int i, int n){
    if(root == NULL){
        return true;
    }
    if(i >= n){
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*i+1, n);
        bool right = isCBT(root->right, 2*i+2, n);
        return (left && right);
    }
}
bool isMaxheap(Node* root){
    //if leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    //only left child
    if(root->right == NULL){
        return root->data > root->left->data;
    }
    else{
        //two child
        bool left = isMaxheap(root->left);
        bool right = isMaxheap(root->right);
        return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
    
}
int main(int argc, char const *argv[])
{
    Node* root = NULL;
    //20 10 7 -1 -1 -1 4 -1 -1
    cout<<"Enter the root value\n";
    root = createTree(root);
    cout<<"\nThe level order traversal of the tree is \n";
    levelOrderTraversal(root);

    int n = Totalnodes(root);
    int i = 0;
    if(isCBT(root, i, n) && isMaxheap(root)){
        cout<<"\nyes";
    }
    else
        cout<<"NO";

    return 0;
}
