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
void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void createMapping(int n, map<int, int> &nodeToIndex,int in[]){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}
Node* solve(int in[], int post[], int n, int &index, int inorderStart, int inorderEnd, map<int, int> &nodeToIndex){
    //base cod
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int val = post[index--];
    Node* root = new Node(val);
    int pos = nodeToIndex[val];

    //in postorder case we are coming from right to left so right will call first or right tree will build first
    root->right = solve(in, post, n, index, pos+1, inorderEnd, nodeToIndex);
    root->left = solve(in, post, n, index, inorderStart, pos-1, nodeToIndex);

    return root;
}
int main(){
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    int index = n-1;
    map<int, int> nodeToIndex;
    createMapping(n, nodeToIndex, in);
    Node* root = solve(in, post, n, index, 0, n-1, nodeToIndex);
    cout<<"Post order Traversal of the tree is ";
    preOrderTraversal(root);
    return 0;
}