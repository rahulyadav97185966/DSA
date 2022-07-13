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
void SumOfLongestPath(Node* root, int len, int &maxlen, int sum, int &maxSum){
        if(root == NULL){
            if(len > maxlen){
                maxlen = len;
                maxSum = sum;
            }
            else if(len == maxlen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        sum = sum + root->data;
        SumOfLongestPath(root->left, len+1, maxlen, sum, maxSum);
        SumOfLongestPath(root->right, len+1, maxlen, sum, maxSum);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    SumOfLongestPath(root, len, maxLen, sum, maxSum);
    cout<<"The Sum of longest path is: "<<maxSum<<endl;
    return 0;
}
