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
vector<int> zigZagTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        //get the size 
        int size = q.size();
        vector<int> temp(size);
        //now process the level
        for(int i=0;i<size;i++){
            Node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size-i-1;
            temp[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }
        //After Traversal change LeftToRight
        leftToRight = !leftToRight;
        for(auto a : temp){
            ans.push_back(a);
        }
    }
    return ans;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"Zig Zag Traversal is: ";
    vector<int> ans = zigZagTraversal(root);
    for(auto a : ans)cout<<a<<" ";

    return 0;
}
