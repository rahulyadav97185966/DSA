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
void buildTreeeUsingLevel(Node* &root){
    queue<Node*> q;
    cout<<"Enter the data for the root node"<<endl;
    int d;
    cin>>d;
    root = new Node(d);
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter data of left "<<temp->data<<endl;
        cin>>d;
        if(d != -1){
            temp->left = new Node(d);
            q.push(temp->left);    
        }
        
        cout<<"Enter data of right "<<temp->data<<endl;
        cin>>d;
        if(d != -1){
            temp->right= new Node(d);
            q.push(temp->right);    
        }
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
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
int main()
{
    Node* root = NULL;
    buildTreeeUsingLevel(root);
    cout<<"\n Level Order Traversal is \n";
    levelOrderTraversal(root);
    return 0;
}