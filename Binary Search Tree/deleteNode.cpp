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
Node* findPred(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* deleteNode(Node* root, int temp){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == temp){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left == NULL && root->right != NULL){
            Node* node = root->right;
            delete root;
            return node;
        }
        if(root->left != NULL && root->right == NULL){
            Node* node = root->left;
            delete root;
            return node;
        }
        //2 child
        if(root->left != NULL && root->right != NULL){
            int pred = findPred(root->right)->data;
            root->data = pred;
            root->right = deleteNode(root->right, pred);
            return root;
        }
    }
    else if(root->data > temp){
        root->left = deleteNode(root->left, temp);
    }
    else{
        root->right = deleteNode(root->right, temp);
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the node\n";
    takeInput(root);
    cout<<"\nThe level order is ";
    leverOrderTraversal(root);
    cout<<"\nTree After the deletion"<<endl;
    root = deleteNode(root, 40);
    leverOrderTraversal(root);
    return 0;
}