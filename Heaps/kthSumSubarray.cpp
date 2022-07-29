#include<bits/stdc++.h>
using namespace std;
//Approach 1 : timecomplexity O(n^2Logn) and space is O(n^2) cause we are using vector for storing
int solve(int *arr, int n, int k){
    vector<int> ans;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[ans.size()-k];
}
//Approach2 : optimised approach Space is O(k)
int solveOptimised(int *arr, int n, int k){
    priority_queue<int, vector<int> , greater<int>> pq;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main(){
    int arr[] = {1,2,6,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    int kthsum = solve(arr, n, k);
    cout<<"kth sum of subarray is "<<kthsum<<endl;
    kthsum = solveOptimised(arr, n, k);
    cout<<"kth sum of subarray is using optimised algo "<<kthsum<<endl;
    return 0;
}