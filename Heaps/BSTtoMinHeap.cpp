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
//Lever Order Traversal Uses Queue
void leverOrderTraversal(Node* root){
    if(root == NULL)return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<"\n";
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
void inorderTraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
void preorderToConvert(Node* &root, vector<int> &ans, int &i){
    if(root == NULL){
        return;
    }
    root->data = ans[i++];
    preorderToConvert(root->left, ans, i);
    preorderToConvert(root->right, ans, i);

}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is \n";
    leverOrderTraversal(root);

    //Convert to to bst
    vector<int> ans;
    inorderTraversal(root, ans);

    cout<<"\nInorder traversal is \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    //convert this inorder to preorder and push
    int i = 0;
    preorderToConvert(root, ans, i);
    cout<<"\nthe tree is \n";
    leverOrderTraversal(root);
    return 0;
}