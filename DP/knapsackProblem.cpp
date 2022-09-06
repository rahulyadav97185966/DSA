#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& val, vector<int>& wt, int i, int capacity){
    //base case
    if(i == val.size() || capacity == 0) 
        return 0;
    int include = 0;

    if(capacity >= wt[i]){
        include += val[i] + solve(val, wt, i+1, capacity-wt[i]);
    }
    int exclude = 0 + solve(val, wt, i+1, capacity);
    return max(include, exclude);
    
}
// Recursion + memoisation
int solve1(vector<int>& val, vector<int>& wt, int i, int capacity, vector<vector<int>>& dp){
    //base case
    if(i == val.size() || capacity == 0) 
        return 0;

    if(dp[i][capacity] != -1)
        return dp[i][capacity];
    int include = 0;

    if(capacity >= wt[i]){
        include += val[i] + solve1(val, wt, i+1, capacity-wt[i], dp);
    }
    int exclude = 0 + solve1(val, wt, i+1, capacity, dp);
    return dp[i][capacity] = max(include, exclude);
}
// Using tabulation
int solve2(vector<int>& val, vector<int>& wt, int n, int C){
    //create dp array
    vector<vector<int>> dp(n+1, vector<int>(C+1, 0));
    //analyse base case and chane accordingly here we already have 0 so no require to change anything
    //apply the loop
    for(int i= n-1;i>=0;i--){
        for(int capacity=0; capacity <= C; capacity++){
            int include = 0;

            if(capacity >= wt[i]){
                include += val[i] + dp[i+1][capacity-wt[i]];
            }
            int exclude = dp[i+1][capacity];
            dp[i][capacity] = max(include, exclude);
        }
    }
    return dp[0][C];
}
//we can do the space optimization for this also... look into it.

int main(){

    int n = 3;
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;

    cout<<"Using recursion: "<<solve(val, wt, 0, W)<<endl;
    // recursion + memo
    // i and capacity is changing so 2d dp required
    // i => 0 to n
    // capacity => capacity -> 0
    // index = row, capacity = col
    vector<vector<int>> dp(n+1,vector<int>(W+1, -1)); 
    cout<<"Using recursion + memoisation is: "<<solve1(val, wt, 0, W, dp)<<endl;
    //Using Tabulation (Bottom Up)
    // in top down our i -> 0 to n here in b.u n to 0
    // capacity is going capacity->0 in b.u it's 0 to capacity
    cout<<"Using Bottom up: "<<solve2(val, wt, n, W)<<endl;

    return 0;
}