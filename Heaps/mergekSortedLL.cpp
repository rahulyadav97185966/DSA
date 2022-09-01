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
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

void print(Node *head)
{
    if (head == NULL)
        return;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *SolveLL(Node *arr[], int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    if (k == 0)
    {
        return NULL;
    }
    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }
    Node *head = NULL;
    Node *tail = NULL;
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();
        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }
        if (head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
int main()
{

    Node *node = new Node(2);
    Node *head1 = node;
    Node *tail1 = node;
    Node *node1 = new Node(4);
    tail1->next = node1;
    tail1 = node1;
    Node *node2 = new Node(6);
    tail1->next = node2;
    tail1 = node2;
    Node *node3 = new Node(1);
    Node *head2 = node3;
    Node *tail2 = node3;
    Node *node4 = new Node(3);
    tail2->next = node4;
    tail2 = node4;

    Node *node5 = new Node(8);
    Node *head3 = node5;
    Node *tail3 = node5;
    Node *node6 = new Node(9);
    tail3->next = node6;
    tail3 = node6;
    Node *node7 = new Node(10);
    tail3->next = node7;
    tail3 = node7;
    cout << "Printing ll 1\n";
    print(head1);
    cout << "Printing ll 2\n";
    print(head2);
    cout << "Printing ll 3\n";
    print(head3);

    Node *arr[] = {head1, head2, head3};

    Node *head = SolveLL(arr, 3);
    print(head);
    return 0;
}
