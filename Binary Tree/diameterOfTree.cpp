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
int diameterOfBinaryTree(Node* root) {
        if(root == NULL)
            return 0;
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = HeightOfTree(root->left)+HeightOfTree(root->right); // here we are calling the Height so height is O(n^2)
        return max(op1, max(op2, op3));
}

//fast Diameter which TC is  O(n) n is numberof nodes
pair<int, int> fastDiameter(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    pair<int, int> leftPair = fastDiameter(root->left);
    pair<int, int> rightPair = fastDiameter(root->right);

    int op1 = leftPair.first;
    int op2 = rightPair.first;
    int op3 = leftPair.second + rightPair.second;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftPair.second, rightPair.second)+1;
    return ans;
}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    
    cout<<"Diameter in n square is "<<diameterOfBinaryTree(root)<<endl;
    cout<<"Diameter in fast way "<<fastDiameter(root).first;
    return 0;
}