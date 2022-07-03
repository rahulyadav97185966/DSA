#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s.push(k);
    }
    while(!s.empty()){
        int r = s.top();
        cout<<r<<" ";
        s.pop();
    }
    
    return 0;
}