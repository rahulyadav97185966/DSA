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
Node* NodeToParentMapping(Node* root, map<Node*, Node*> &parentMapping, int target ){
    
    Node* temp = NULL;
    queue<Node*> q;
    q.push(root);
    parentMapping[root] = NULL;
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode->data == target){
            temp = frontNode;
        }
        if(frontNode->left){
            parentMapping[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        if(frontNode->right){
            parentMapping[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return temp;
}
int Burntree(Node* targetNode, map<Node*, Node*> &parentMapping){
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(targetNode);
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        bool AnyChange = 0;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            //Now need to check three condi left, right and parent
            if(temp->left && visited[temp->left] != 1){
                AnyChange = 1;
                visited[temp->left] = 1;
                q.push(temp->left);
            }
            if(temp->right && visited[temp->right] != 1){
                AnyChange = 1;
                visited[temp->right] = 1;
                q.push(temp->right);
            }
            if(parentMapping[temp] && visited[parentMapping[temp]] != 1){
                AnyChange = 1;
                visited[parentMapping[temp]] = 1;
                q.push(parentMapping[temp]);
            }
        }
        if(AnyChange == 1){
            ans++;
        }
    }
    return ans;
}
int main(){
    Node* root = NULL;
    //1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    root = buildTree(root);
    int target;
    cout<<"\nEnter the target Node "<<endl;
    cin>>target;
    //Algorithm
    //Step1: Create NodetoParentMapping
    //Step2: find the target Node;
    //Step3: Burn the Tree in minTime;
    map<Node*, Node*> ParentMapping;
    Node* targetNode = NodeToParentMapping(root, ParentMapping, target);
    int ans = Burntree(targetNode, ParentMapping);
    cout<<"\nThe time required is "<<ans<<endl;
    return 0;
}