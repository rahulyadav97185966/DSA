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
void kthAncestorUsingvector(Node* root, vector<int> &v, int node, int k, int ans){
    if(root == NULL)
        return;
    int r = root->data;
    v.push_back(root->data);
    if(root->data == node){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        v.pop_back();
        return;
    }
    kthAncestorUsingvector(root->left,v,node,k, ans);
    kthAncestorUsingvector(root->right,v,node,k, ans);

}
Node* kthAncestor(Node* root, int &k, int node){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    Node* leftAns = kthAncestor(root->left, k, node);
    Node* rightAns = kthAncestor(root->right, k, node);
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k < 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k < 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int main(){
    Node* root = NULL;
    //1 2 4 -1 -1 5 -1 7 8 -1 -1 9 -1 -1 3 6 -1 -1 -1
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    int k = 2;
    Node* node1 = kthAncestor(root, k, 4);
    if(node1 == NULL || node1->data == 4){
        cout<<"-1";
    }
    cout<<node1->data<<"\n";
    vector<int> v;
    kthAncestorUsingvector(root, v, 9, 3, -1);
    for(auto i : v)cout<<i<<" ";
    
    return 0;
}
