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
vector<int> MergeArrays(vector<int> ans, vector<int> ans1){
    vector<int> answer;
    int i = 0;
    int j = 0;
    while(i < ans.size() && j < ans1.size()){
        if(ans[i] < ans1[j]){
            answer.push_back(ans[i++]);
        }
        else{
            answer.push_back(ans1[j++]);
        }
    }
    while(i < ans.size()){
        answer.push_back(ans[i++]);
    }
    while(j < ans1.size()){
        answer.push_back(ans1[j++]);
    }
    return answer;
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
    cout<<"Enter the node for BST1\n";
    takeInput(root);
    cout<<"Enter the node for BST2";
    Node* root1 = NULL;
    takeInput(root1);

    cout<<"\nThe level order for BST1\n";
    leverOrderTraversal(root);
    cout<<"\nThe level order for BST2\n";
    leverOrderTraversal(root1);
    //first to inorder traversal
    vector<int> ans,ans1;
    inorder(root, ans);
    inorder(root1, ans1);
    //Now Merge Two vectors now
    cout<<"The ans is\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<"\nThe ans1 is\n";
    for(int i=0;i<ans1.size();i++)cout<<ans1[i]<<" ";
    vector<int> answer = MergeArrays(ans, ans1);
    cout<<"The answer of the 3 is ";
    for(int i=0;i<answer.size();i++)cout<<answer[i]<<" ";
    Node* rootOfTree = createTree(0,answer.size()-1,answer);
    cout<<"\nThe level order for BST3\n";
    leverOrderTraversal(rootOfTree);
    
    return 0;
}