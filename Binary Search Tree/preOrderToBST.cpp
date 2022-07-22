#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = left;
        this->right = right;
    }
};
//Lever Order Traversal Uses Queue
void leverOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
Node* solve(int preorder[], int mini, int maxi, int n, int &i){
    if(i >= n){
        return NULL;
    }
    if(preorder[i] < mini || preorder[i] > maxi){
        return nullptr;
    }
    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, n, i);
    root->right = solve(preorder, root->data, maxi, n, i);
    return root;
}
int main(){

    int preorder[8] = {20, 10, 5, 15, 13, 35, 30, 42};
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int n = 8;
    int i = 0;
    Node* root = solve(preorder, mini, maxi, n, i);
    cout<<"The level order traversal is \n";
    leverOrderTraversal(root);

    return 0;
}