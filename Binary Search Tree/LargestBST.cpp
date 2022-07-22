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
class Info{
    public:
        int size;
        int mini;
        int maxi;
        bool isBST;
        int sum;
    Info(){
        this->size = 0;
        this->mini = INT_MAX;
        this->maxi = INT_MIN;
        this->isBST = true;
        this->sum = true;
    }
    Info(int size, int mini, int maxi, bool isBST, int sum){
        this->size = size;
        this->mini = mini;
        this->maxi = maxi;
        this->isBST = isBST;
        this->sum = sum;
    }
};
Node* buildTree(Node* &root){
    cout<<"Enter the data\n";
    int d;
    cin>>d;
    root = new Node(d);
    if(d == -1){
        return NULL;
    }
    cout<<"Enter the data for left "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right "<<d<<endl;
    root->right = buildTree(root->right);
    return root;
}
void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {   
        Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}
Info LargestBST(Node* root,int &ans, int &sum){
    //base cond
    if(root == NULL){
        return Info{0, INT_MAX, INT_MIN, true, 0};
    }
    //solve for left
    Info leftAns = LargestBST(root->left, ans, sum);
    //solve for right
    Info rightAns = LargestBST(root->right, ans, sum);

    //Info current ans
    Info curr;
    curr.size = leftAns.size + rightAns.size + 1;
    curr.mini = min(leftAns.mini, root->data);
    curr.maxi = max(rightAns.maxi, root->data);
    
    if(leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxi && root->data < rightAns.mini)){
        curr.isBST = true;
        curr.sum = leftAns.sum + rightAns.sum + root->data;
    }
    else{
        curr.isBST = false;
        curr.sum = 0;
    }
    if(curr.isBST){
        ans = max(ans, curr.size);
        sum = max(sum, curr.sum);
    }
    return curr;

}
int main(){
    //50 30 5 -1 -1 20 -1 -1 60 45 -1 -1 70 65 -1 -1 80 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    cout<<"\nThe level order traversal of tree "<<endl;
    LevelOrderTraversal(root);
    int ans = 0;
    int sum = 0;
    LargestBST(root, ans, sum);
    cout<<"\nThe Largest BST size is "<<ans;
    cout<<"\nSum of Largest BST is "<<sum;
    
    return 0;
}