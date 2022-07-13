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
    cout<<"Enter the data"<<endl;
    int d;
    cin>>d;
    root = new Node(d);

    if(d == -1){
        return NULL;
    }
    cout<<"Enter the value of the left "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value of the right "<<d<<endl;
    root->right = buildTree(root->right);
}
void TopView(Node* root, vector<int> &ans){
    if(root == NULL)
        return;
    map<int, int> topNode;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto a : topNode){
        ans.push_back(a.second);
    }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> ans;
    TopView(root, ans);
    cout<<"The Top view of the tree is "<<endl;
    for(auto a : ans)cout<<a<<" ";

    return 0;
}
