#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    //Construture to create a node
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

//Print the Doubly Linked List
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

//Return the length of the LL
int LengthOfLL(Node*  &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    cout<<"the count of the linked list is"<<count<<endl;
    return count;
}


//insert at the begining
void insertAtStart(Node* &head, int data) {

    //First Create the node
    Node* temp = new Node(data);
    //if the linked list is null
    if(head == NULL){
        head = temp;
    }
    else{
        temp -> next = head;
        head->prev = temp;
        head = temp;
    }
}

//insert at the end without using tail
void insertAtTail(Node* &head, int data, Node* &tail){

    //First Create the node
    Node* temp = new Node(data);

    //if linked list is empty
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        Node* prevNode = head;
        while(prevNode->next != NULL){
            prevNode = prevNode->next;
        }
        prevNode -> next = temp;
        temp->prev = prevNode;
        tail = temp;
    }
}

//insert at the end using tail
void insertAtTailUsingTail(Node* &tail, int data){

    //First Create the node
    Node* temp = new Node(data);

    //if linked list is empty
    if(tail == NULL){
        tail = temp;
    }
    else{
       temp -> prev = tail;
       tail ->next = temp;
       tail = temp;
    }
}

//insert at the middle of the LL
void insertMiddle(Node* &head, int pos, int data, Node* &tail){

    if(pos-1 > LengthOfLL(head)){
        cout<<"pos should be less than the length"<<"\n";
        return;
    }
    else{
        // if Position is given as first position
        if(pos == 1){
            //create the node
            Node *temp = new Node(data);
            temp -> next = head;
            head->prev = temp;
            head = temp;
        }
        else if(pos-2 == (LengthOfLL(head)-1)){  //if we want to insert at the end
            insertAtTail(head,data,tail);
        }
        else{
            //Create node
            Node* newNode = new Node(data);
            Node* temp = head;
            pos = pos - 2;
            while(pos--){
                temp = temp->next;
            }
            newNode->next = temp -> next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
}

//Delete element give the target not position
void deleteElementTarget(Node* &head, int target, Node* tail){

    //if Linkedlist is empty
    if(head == NULL){
        cout<<"LL is empty "<<endl;
        return;
    }
    else{
        //if element is foud at first pos and lenght of LL is 1
        if(head->data == target && LengthOfLL(head) == 1){
            delete head;
            return;
        }
        else if(head->data == target){ //element found at first pos and Length is > 1
            Node* temp = head;
            head = head -> next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else{
            Node* temp = head;
            while(temp->data != target && temp->next != NULL){
                temp = temp->next;
            }
            //now target is not found
            if(temp->next == NULL && temp->data != target){
                cout<<"Element is not found in the LL"<<endl;
                return;
            }
            else if(temp->next == NULL) { // element is found at end
                Node* s = temp;
                temp = temp->prev;
                tail = temp->prev;
                temp->next = NULL;
                s->prev = NULL;
                delete s;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = temp->prev = NULL;
                delete temp;
            }

        }
    }

}


int main(){

    //Create a Doubly Linked List Node
    Node* node = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    head = node;
    tail = node;
    print(head);
    insertAtStart(head, 11);
    print(head);
    insertAtTail(head,12,tail);
    print(head);
    insertAtTailUsingTail(tail,13);
    print(head);
    insertMiddle(head, 5, 14, tail);
    print(head);
    deleteElementTarget(head, 11,tail);
    print(head);



    return 0;
}
