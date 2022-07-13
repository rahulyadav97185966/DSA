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

// Inserting element at the Head
void insertAtHead(Node *&head, int data)
{
    // First need to create a node
    Node *temp = new Node(data);
    // now connect the temp->next to the head and then assign head to temp
    temp->next = head;
    head = temp;
}

// Inserting element at the Tail
void insertAtTail(Node *&head, int data)
{
    // First create the node;
    Node *temp = new Node(data);

    // Now go till the last linked list whose next is null
    //  For that we need to create a temp variable
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    // Now temp is reached till last linked list element not assign value to it
    temp2->next = temp;
}

int countEle(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << "count is " << count << "\n";
    return count;
}

// Insert at the middle
void insertAtMiddle(Node *&head, int pos, int data)
{

    Node *temp1 = head;
    int cnt = 1;

    // if position is starting position
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    if (pos > countEle(head))
    {
        cout << "Invalid Position";
        return;
    }
    while (cnt < pos - 1)
    {
        temp1 = temp1->next;
        cnt++;
    }
    // Again First Create the node
    Node *temp = new Node(data);
    // Then assign data to previous and next node
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteTargetNode(Node *&head, int target, int pos)
{
    // empty list
    if (head == NULL)
    {
        return;
    }
    // take temp node to traverse
    Node *temp = head;
    Node *prev = NULL;
    if (target == temp->data && pos == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        while (temp != NULL && temp->data != target)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Not found element"
                 << "\n";
            return;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

// To Print the linked List
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    // creation of a node
    Node *node1 = new Node(7);
    // pointing head to the node
    Node *head = node1;
    print(head);

    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    Node* P = new Node(-1);
    P = head -> next -> next -> next ;
    P -> next -> next -> next -> next = head -> next -> next -> next -> next;
    head -> next -> next -> next = P -> next -> next;
    int X = head -> next -> next -> next -> next -> next -> next -> next -> data; 
    cout<<X;
    return 0;
}