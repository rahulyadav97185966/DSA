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
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    //first to inorder traversal
    vector<int> ans;
    inorder(root, ans);
    int target = 20;
    int i = 0;
    int j = ans.size()-1;
    bool flag = 1;
    while(j > i){
        if(ans[i]+ans[j] == target){
            cout<<"True";
            flag = 0;
            break;
        }
        if(ans[i]+ans[j] > target){
            j--;
        }
        else{
            i++;
        }
    }
    if(flag == 1)cout<<"False";
    return 0;
}