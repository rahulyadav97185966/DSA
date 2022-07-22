#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
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
Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        //insert to right
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = insertIntoBST(root, d);
        cin>>d;
    }
}
void validateBST(Node* root, vector<int>& ans){
    //base codnn
    if(root == nullptr)return;
    validateBST(root->left, ans);
    ans.push_back(root->data);
    validateBST(root->right, ans);
}
//without veectir
bool validateBST1(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = validateBST1(root->left, min, root->data);
        bool right = validateBST1(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);   
    cout<<"\nThe tree is BST or NOT by using vector ";
    vector<int> ans;
    validateBST(root, ans);
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i] > ans[i+1]){
            cout<<"false"<<endl;
            break;
        }
    }
    cout<<"True"<<endl;
    //without using the vector
    cout<<"The tree is BST or not "<<validateBST1(root, INT_MIN, INT_MAX);
    return 0;
}