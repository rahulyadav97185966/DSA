#include<bits/stdc++.h>
using namespace std;
int getMinimumElement(stack<int> st, int  element){
    if(st.empty()){
        return -1;
    }
    int topElement = st.top();
    st.pop();
    if(topElement < element){
        st.push(topElement);
        return topElement;
    }
    return getMinimumElement(st, element);
}
int main(){
    int arr[] = {3, 5, 4, 2};
    //Start from the end 
    int n = sizeof(arr)/sizeof(arr[0]);
    stack<int> st;
    vector<int> v;
    //Traverse the link from end to first
    for(int i=n-1;i>=0;i--){
        int val = getMinimumElement(st, arr[i]);
        st.push(arr[i]);
        v.push_back(val);
    }
    reverse(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}