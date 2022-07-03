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

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50); 


    insertAtBottom(st,90);
    
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}