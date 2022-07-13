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
void LeftView(Node* root, vector<int> &ans, int level){
    if(root == NULL)
        return;
    //we entered into the new level
    if(level == ans.size())
        ans.push_back(root->data);
    LeftView(root->left, ans, level+1);
    LeftView(root->right, ans, level+1);
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> ans;
    LeftView(root, ans, 0);
    cout<<"The left view of the tree is "<<endl;
    for(auto a : ans)cout<<a<<" ";

    return 0;
}
