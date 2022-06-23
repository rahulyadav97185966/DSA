#include <bits/stdc++.h>
using namespace std;
// This is a Structure of linked list using the class, We can also use Struture as well no issues into it as well
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertatEnd(Node* &last, int data){
    //Create a node
    Node *node = new Node(data); 
    cout<<node->data<<" \n";
    if(last == NULL){
        cout<<"inside the if"<<endl;
        last = node;
        node->next=node;
    }
    else{
        cout<<"inside the else"<<endl;
        node->next = last->next;
        last->next = node;
        last = node;
    }
}

void insertAtBegin(Node* &last, int data) {
    //Create a node
    Node* node = new Node(data);
    
    //if last is empty
    if(last == NULL){
        last = node;
        node->next = node;
    }
    else{
        node->next = last->next;
        last->next = node;
    }
}

void DeletionOfNode(Node* &last, int target) {
    if(last == NULL){
        cout<<"LL is empty";
        return;
    }
    else{
        Node* temp = last;
        while(temp->next->data != target && temp != last){
            temp = temp->next;
        }
        if(temp->next->data != target){
            cout<<"not found";
            return;
        }
        if(temp->next->data == target && temp->next == last && last->next == last){
            delete last;
            return;
        }
        if(temp->next->data == target && temp->next == last){
            last = last->next;
            Node* temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = NULL;
            delete temp1;
        }
    }
}

void traverse(Node* &last){
    if(last == NULL){
        return;
    }
    else{
        Node* temp = last->next;
        while(temp != last){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
}


int main()
{
    // creation of a node
    Node *node1 = new Node(10);
    Node *last = node1;
    last->next = node1;
    // Why node if pointing to last?
    // becuase if we point it tot the first or head then we need to traverse whole list to insert element at first and last 
    // because to avoid this traversing we pointed to the last node
    insertatEnd(last,11);
    insertatEnd(last,12);
    insertAtBegin(last,13);
    insertAtBegin(last,14);
    insertAtBegin(last,15);
    traverse(last);
    DeletionOfNode(last, 15);
    traverse(last);
    
    return 0;
}