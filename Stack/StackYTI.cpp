#include<bits/stdc++.h>
using namespace std;
class Stack{
    //properties
    public:
        int *arr;
        int top, size;

    //behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int ele){
        if(top == size-1){
            cout<<"Space is not available"<<endl;
            return;
        }
        top++;
        arr[top] = ele;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        top--;
    }
    int peak(){
        if(top >=0){
            return arr[top];
        }
        cout<<"Stack is empty";
        return -1;
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    void print(int top){
        if(top == -1){
            return;
        }
        int ele = arr[top];
        cout<<ele<<" ";
        top--;
        print(top);
        push(ele);
    }
};

int main(){
    //Creation of stack
    stack<int> s;
    //push element into the stack
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(13);

    //popelement into the stack
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    //check wheather stack is empty
    cout<<s.empty();

    //check size of stack
    cout<<"\n size of stack is"<<s.size()<<endl;

    //Implement stack using class
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"\n"<<st.peak()<<endl;
    cout<<st.isEmpty()<<endl;

    st.print(st.peak());
    return 0;
}