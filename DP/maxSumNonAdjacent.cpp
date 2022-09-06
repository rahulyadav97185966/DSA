#include<bits/stdc++.h>
using namespace std;
// Recursion
int solve(vector<int>& arr, int i){
    if(i >= arr.size()) return 0;

    int incl = arr[i] + solve(arr, i+2);
    int exclude = 0 + solve(arr, i+1);
    return max(incl, exclude);
}
// recursion + memoisation
int solve1(vector<int>& arr, int i, vector<int>& dp){
    if(i >= arr.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int incl = arr[i] + solve1(arr, i+2, dp);
    int exclude = 0 + solve1(arr, i+1, dp);
    return dp[i] = max(incl, exclude);
}
// Bottom Up 
int solve2(vector<int>& arr){
    vector<int> dp(arr.size()+2, 0);
    int n = arr.size();
    for(int index=n-1;index>=0;index--){
        int incl = arr[index] + dp[index+2];
        int exclude = 0 + dp[index+1];
        dp[index] = max(incl, exclude);
    }
    return dp[0];
}
// dp depends on index+1 and index+2;
int solve3(vector<int>& arr){
    
    int next1 = 0;
    int next2 = 0;
    int current;
    int n = arr.size();
    for(int index=n-1;index>=0;index--){
        int incl = arr[index] + next2;
        int exclude = next1;
        current = max(incl, exclude);
        next2 = next1;
        next1 = current;
    }
    return next1;
}
int main(){
    vector<int> arr = {2,1,4,9};
    int sum = 0;
    int maxi = INT_MIN;
    //recursion
    cout<<solve(arr, 0)<<endl;
    //recursion+memo
    vector<int> dp(arr.size()+1, -1);
    cout<<solve1(arr,0, dp)<<endl;
    // tabulation
    cout<<solve2(arr)<<endl;
    // Space optimization
    cout<<solve3(arr)<<endl;
    return 0;
}