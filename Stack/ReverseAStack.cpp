#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int topelem){
    if(st.empty()){
        st.push(topelem);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtBottom(st, topelem);
    st.push(ele);
}

void ReverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    //Step1: get top element
    int topelement = st.top();
    st.pop();
    //Step2 : recursive call
    ReverseStack(st);
    //Step3 : call insert at bottom
    insertAtBottom(st, topelement);
}

int main(){
    
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50); 


    //insertAtBottom(st,90);
    ReverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}