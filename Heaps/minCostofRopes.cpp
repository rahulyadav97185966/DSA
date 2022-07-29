#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {4,3,2,6};
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : arr)pq.push(i);
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int z = a+b;
        pq.push(z);
        ans += z;
    }
    cout<<"Answer is "<<ans;

    return 0;
}