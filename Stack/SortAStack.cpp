#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int topElement){
    if(st.empty() || topElement >= st.top()){
        st.push(topElement);
        return;
    }
    int k = st.top();
    st.pop();
    sortedInsert(st, topElement);
    st.push(k);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int topEle = st.top();
    st.pop();
    // Recursive call untill empty
    sortStack(st);
    //Call the Sort in Insert Method
    sortedInsert(st, topEle);
}

int main(){
    stack<int> st;
    st.push(11);
    st.push(2);
    st.push(30);
    st.push(12);
    st.push(5); 
    st.push(27); 

    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}