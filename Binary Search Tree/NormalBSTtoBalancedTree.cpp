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
void inorder(Node* root, vector<int> &ans){
    if(root == NULL)return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
Node* createTree(int s, int e, vector<int> &ans){
    if(s > e){
        return NULL; 
    }
    int mid = (s+e)/2;
    Node* root = new Node(ans[mid]);
    root->left = createTree(s,mid-1,ans);
    root->right = createTree(mid+1,e,ans);
    return root;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    //first to inorder traversal
    vector<int> ans;
    inorder(root, ans);
    root = createTree(0, ans.size()-1, ans);
    cout<<"level order after ";
    leverOrderTraversal(root);

    return 0;
}