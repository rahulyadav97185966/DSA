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
void Diagonaltraversal(Node* root, int lvl, map<int, vector<int>> &diagonalMap){
    if(root == NULL){
        return;
    }
    diagonalMap[lvl].push_back(root->data);
    //if has left child then increase the lvl
    Diagonaltraversal(root->left,lvl+1,diagonalMap);
    //for right child do not increase the lvl
    Diagonaltraversal(root->right,lvl,diagonalMap);
}
int main(){
    Node* root = NULL;
    //8 3 1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> ans;
    map<int, vector<int>> diagnalMap;
    Diagonaltraversal(root, 0, diagnalMap);
    cout<<"The Diagonal view of the tree is "<<endl;
    for(auto i : diagnalMap){
        for(auto j : i.second){
            cout<<j<<" ";
        }
    }

    return 0;
}
