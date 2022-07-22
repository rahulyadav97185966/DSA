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
void convertIntoSortedDLL(Node* root, Node*  &head){
    //base case
    if(root == NULL)
        return;
    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convertIntoSortedDLL(root->left, head);
}
Node* MergeTwoLL(Node* &head1, Node* &head2){
    Node* head = NULL;
    Node* tail = NULL;
    while(head1 != NULL && head2 != NULL){
        cout<<head1->data<<" "<<head2->data<<endl;
        if(head1->data <= head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        if(head == NULL){
            head = head1;
            tail = head1;
            head1 = head1->right;
        }
        else{
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    }
    while(head2 != NULL){
        if(head == NULL){
            head = head2;
            tail = head2;
            head2 = head2->right;
        }
        else{
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }
    return head;
}
int TotalNode(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
Node* SortedLLToBST(Node* &head, int n){
    if(n <= 0 || head == NULL){
        return NULL;
    }
    Node* leftNode = SortedLLToBST(head, n/2);
    Node* root = head;
    root->left = leftNode;
    head = head->right;
    root->right = SortedLLToBST(head, n- n/2 - 1);
    return root;
}
int main(){


    int j =1, num1 = 4;
    while(++j<=10){
        num1++;
    }
    cout<<num1;

    //Create two BST
    Node* root = NULL;
    cout<<"Enter the node for BST1\n";
    takeInput(root);
    cout<<"Enter the node for BST2";
    Node* root1 = NULL;
    takeInput(root1);

    //Step1 : Convert it to Sorted linked list
    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    head->left = NULL;

    cout<<"Printing the head list"<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    cout<<"Printing the head1 list"<<endl;
    temp = head1;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }

    //Step 2 : Merge two Sorted LL

    head = MergeTwoLL(head, head1);

    cout<<"Printing the merged LL"<<endl;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    //Step3 : Create BST from it;
    root = SortedLLToBST(head, TotalNode(head));

    //Print the level order traversal
    cout<<"The Level order traversal is \n";
    leverOrderTraversal(root);

    return 0;
}
