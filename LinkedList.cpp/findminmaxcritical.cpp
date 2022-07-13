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
    cout << "\n\n";
    vector<int> v = {-1, -1};
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        cout<<"fine";
    }
    Node *prev = head;
    Node *currentNode = head->next;

    int index = 2;
    int first_index = 0;
    int prev_index = 0;
    int minDist = INT_MAX;
    int maxDist = INT_MIN;
    while (currentNode->next != NULL)
    {
        if (prev->data < currentNode->data && currentNode->next->data < currentNode->data)
        {
            // this is maxima
            if (first_index == 0)
            {
                first_index = index;
                prev_index = index;
            }
            else
            {
                minDist = min(minDist, index - prev_index);
                prev_index = index;
                maxDist = max(maxDist, index - first_index);
            }
        }
        else if (prev->data > currentNode->data && currentNode->next->data > currentNode->data)
        {
            // this is minima
            if (first_index == 0)
            {
                first_index = index;
                prev_index = index;
            }
            else
            {
                minDist = min(minDist, index - prev_index);
                prev_index = index;
                maxDist = max(maxDist, index - first_index);
            }
        }
        index++;
        prev = prev->next;
        currentNode = currentNode->next;
    }
    v[0] = minDist;
    v[1] = maxDist;
    cout << v[0] << " " << v[1];

    return 0;
}
