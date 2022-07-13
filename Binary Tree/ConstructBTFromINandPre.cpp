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
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//using this tc is  n^2
int FindPosition(int val, int in[], int n){
    for(int i=0;i<n;i++){
        if(in[i] == val)
            return i;
    }
    return -1;
}
//using map insertion is logn and n times we are doing so nlogn overall
void createmapping(int in[],map<int, int>  &nodeToIndex,int n){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]] = i;
    }
}
Node* buildTree(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> nodeToIndex){
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    int val = pre[index++];
    Node* root = new Node(val);
    int pos = nodeToIndex[val];
    //int pos = FindPosition(val,in, n);
    root->left = buildTree(in,pre,index,inOrderStart,pos-1, n, nodeToIndex);
    root->right = buildTree(in,pre,index,pos+1,inOrderEnd, n, nodeToIndex);
    return root;
}
int main(){
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 6;
    int index = 0;
    map<int, int> nodeToIndex;
    //create nodes to index mapping
    createmapping(in, nodeToIndex, n);
    Node* root = buildTree(in, pre, index, 0, n-1, n, nodeToIndex);
    postOrder(root);
    return 0;
}