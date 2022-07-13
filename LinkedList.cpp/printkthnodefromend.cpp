#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
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
int printkth(Node* temp, int k){
        if(temp == NULL){
            return 0;       
        }
        int cnt = printkth(temp->next, k)+1;
        if(cnt == k){
            cout<<temp->data<<" ";
        }
        return cnt;
    }
int main()
{
    Node *node1 = new Node(7);
    Node *head = node1;
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    print(head);
    
    int k = 2;
    int val = printkth(head,k);
    cout<<val<<" ";
    

    
    return 0;
}
