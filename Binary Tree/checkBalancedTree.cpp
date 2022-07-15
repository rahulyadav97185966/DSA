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

int HeightOfTree(Node* root){
    if(root == NULL)
        return 0;
    
    int leftHeight = HeightOfTree(root->left);
    int rightHeight = HeightOfTree(root->right);

    return max(leftHeight, rightHeight)+1;
}
bool isBalanced(Node* root) {
    if(root == NULL){
        return true;
    }
    bool leftSub = isBalanced(root->left);
    bool rightSub = isBalanced(root->right);        
    bool ans = abs(HeightOfTree(root->left) - HeightOfTree(root->right)) <= 1;
    return leftSub && rightSub && ans;
        
}
    
//fast Diameter which TC is  O(n) n is numberof nodes
pair<bool, int> balancedFast(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true,0);
        return p;
    }
    pair<bool, int> leftPair = balancedFast(root->left);
    pair<bool, int> rightPair = balancedFast(root->right);

    bool leftAns = leftPair.first;
    bool rightAns = rightPair.first;
    int diff = abs(leftPair.second - rightPair.second ) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftPair.second, rightPair.second)+1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else
        ans.first = false;
    return ans;
}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    
    cout<<"Check balanced in n square TC is "<<isBalanced   (root)<<endl;
    cout<<"checkbalanced in fast way "<<balancedFast(root).first;
    return 0;
}