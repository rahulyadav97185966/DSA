#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[] = {7,10,4,3,20,15};
    int k = 4;
    int n = 6;
    priority_queue<int> pq;
    //step1: build heap
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    //step2: for remaining
    for(int i=k;i<n;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //ans = pq.top();
    cout<<"kth smallest element is "<<pq.top();
    return 0;
}
