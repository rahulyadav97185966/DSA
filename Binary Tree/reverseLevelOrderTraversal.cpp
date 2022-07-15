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
    cout<<"Enter the data";
    int d;
    cin>>d;
    root = new Node(d);
    if(d == -1){
        return NULL;
    }
    cout<<"Enter value for left of node "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter value for right of node "<<d<<endl;
    root->right = buildTree(root->right);
}
void ReverseLevelOrderTraversal(Node* root){
    stack<Node*> st;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        st.push(front);
        if(front->right){
            q.push(front->right);
        }
        if(front->left){
            q.push(front->left);
        }
    }
    while (!st.empty())
    {
        Node* temp = st.top();
        cout<<temp->data<<" ";
        st.pop();
    }
}
int main(){
    Node* root = NULL;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    root = buildTree(root);
    cout<<"\nMorris traversal is "<<endl;
    ReverseLevelOrderTraversal(root);
    return 0;
}