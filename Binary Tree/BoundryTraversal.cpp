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
void traverseLeft(Node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}
void TraverseLeaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    TraverseLeaf(root->left, ans);
    TraverseLeaf(root->right, ans);
}
void traverseRight(Node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    //if return
    ans.push_back(root->data);
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> ans;
    ans.push_back(root->data);
    //Traverse the Left Part
    traverseLeft(root->left, ans);
    //Traverse the Leaf Nodes Only
    //traverse left first
    TraverseLeaf(root->left, ans);
    //then right
    TraverseLeaf(root->right, ans);
    //Now the right part
    traverseRight(root->right, ans);

    cout<<"Boundry traversal of the tree is "<<endl;
    for(auto a : ans)cout<<a<<" ";

    return 0;
}
