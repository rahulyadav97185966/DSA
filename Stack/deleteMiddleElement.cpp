#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int total_size){
    if((total_size/2)+1 == st.size()){
        st.pop();
        return;
    }
    int ele = st.top();
    st.pop();
    deleteMiddle(st, total_size);
    st.push(ele);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50); 
    st.push(60); 

    deleteMiddle(st, st.size());
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}