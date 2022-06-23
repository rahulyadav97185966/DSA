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
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

Node* Reverse(Node* &head){
    //if linked list is empty
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    else{
        Node* current = head; // these three we need cause we need to reverse linked list
        Node* prev = NULL; 
        while(current != NULL){
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }
    return 0;
}

Node* reverseLL(Node* current, Node* prev){
    if(current == NULL){
        return  prev;
    }
    //Connection Change
    Node* next_node = current->next;
    current->next = prev;
    return reverseLL(next_node,current);
}

int main()
{
    // creation of a node
    Node *node1 = new Node(10);
    Node* head = node1;
    Node *node2 = new Node(20);
    node1->next = node2;
    Node *node3 = new Node(30);
    node2->next = node3;
    Node *node4 = new Node(40);
    node3->next = node4;
    Node *node5 = new Node(50);
    node4->next = node5;
    print(head);
    Node* ans_head = reverseLL(head, NULL);
    print(ans_head);
    cout<<"ans is"<<ans_head->data<<"\n";
    
    return 0;
}