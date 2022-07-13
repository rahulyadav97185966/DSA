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
void VerticalTraversal(Node* root, vector<int> &ans){
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node*, pair<int, int > > > q;
    if(root == NULL){
        return;
    } 
    q.push(make_pair(root, make_pair(0,0)));
    while (!q.empty())
    {
        pair<Node*, pair<int, int> > temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }
    for(auto i : nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(root == NULL){
        cout<<"ERROR";
    }
    vector<int> ans;
    VerticalTraversal(root, ans);    
    for(auto a : ans)cout<<a<<" ";

    return 0;
}
