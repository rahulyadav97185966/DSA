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
pair<bool, int> SumTree(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = SumTree(root->left);
    pair<bool, int> rightAns = SumTree(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool cond = root->data == leftSum+rightSum;
    pair<bool, int> ans;
    if(isLeftSumTree && isRightSumTree && cond){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }
    return ans;

}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"The Tree is Sum or Not: "<<SumTree(root).first<<endl;

    return 0;
}
