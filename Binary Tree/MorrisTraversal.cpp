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
Node* findPred(Node* current){
    Node* pre = current->left;
    while(pre->right != NULL && pre->right != current){
        pre = pre->right;
    }
    return pre;
}
void MorrisTraversal(Node* root){
    if(root == NULL){
        return;
    }
    Node* current = root;
    while(current != NULL){
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            Node* predesor = findPred(current);
            if(predesor->right == NULL){
                predesor->right = current;
                current = current->left;
            }
            else{
                predesor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }

}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"\nMorris traversal is "<<endl;
    MorrisTraversal(root);
    return 0;
}