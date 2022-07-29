#include<bits/stdc++.h>
using namespace std;
int signum(int a, int b){
    if(a == b)return 0;
    if(a > b)return 1;
    else return -1;
}
int calculateMedian(int ele, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median){
    cout<<"median inside the: "<<median<<endl;
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if(ele > median){
            mini.push(ele);
            median = mini.top();
        }
        else{
            maxi.push(ele);
            median =  maxi.top();
        }
        break;
    case 1:
        if(ele > median){
            mini.push(ele);
        }
        else{
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(ele);
        }
        median =  (mini.top()+maxi.top())/2;
        break;
    case -1:
        if(ele > median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(ele);
        }
        else{
            maxi.push(ele);
        }
        median =  (mini.top()+maxi.top())/2;
        break;
    default:
        break;
    }
}
vector<int> solve(int arr[], int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median  = 0;
    for(int i=0;i<n;i++){
        int ele = arr[i];
        cout<<median<<"\n";
        calculateMedian(ele, maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int arr[] = {4,6,3,8,9,7};
    int size = 6;
    vector<int> ans = solve(arr, size);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}
