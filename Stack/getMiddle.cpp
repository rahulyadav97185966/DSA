#include<bits/stdc++.h>
using namespace std;

int getMiddle(stack<int> &st){
    //totalsize/2+1 == size
    if((st.size()/2)+1 == st.size()){
        return st.top();
    }
    int ele = st.top();
    st.pop();
    return getMiddle(st);
    st.push(ele);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<getMiddle(st);
    return 0;
}