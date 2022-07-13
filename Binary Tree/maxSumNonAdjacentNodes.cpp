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
pair<int, int> solve(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> res;
    res.first = root->data + leftAns.second + rightAns.second;
    res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    return res;  
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    pair<int, int> ans = solve(root);
    cout<<"Answer is: "<<max(ans.first, ans.second);


    return 0;
}
