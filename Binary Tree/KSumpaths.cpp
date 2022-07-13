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
void kSum(Node* root, vector<int> path, int &count, int k){
    if(root == NULL)
        return;
    path.push_back(root->data);
    kSum(root->left, path, count, k);
    kSum(root->right, path, count, k);

    int sum = 0;
    int size = path.size();
    for(int i=size-1;i>=0;i--){
        sum += path[i];
        if(sum == k)
            count++;
    }
    path.pop_back();
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> path;
    int count = 0;
    int k;
    cout<<"enter the value of K \n";
    cin>>k;
    kSum(root, path, count, k);
    cout<<"Count of the total paths are "<<count;
    return 0;
}
