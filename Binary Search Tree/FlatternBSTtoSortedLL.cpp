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
//Will first do inorder traversal
void inorder(Node* root, vector<Node*> &ans){
    if(root == NULL)return;
    inorder(root->left, ans);
    ans.push_back(root);
    inorder(root->right,ans);
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    //first to inorder traversal
    vector<Node*> ans;
    inorder(root, ans);
    Node* temp = ans[0];
    for(int i=0;i<ans.size()-1;i++){
        ans[i]->left = NULL;
        ans[i]->right = ans[i+1];
    }
    ans[ans.size()-1]->left = NULL;
    ans[ans.size()-1]->right = NULL;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}