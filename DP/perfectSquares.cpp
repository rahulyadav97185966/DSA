#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    if( n == 0) return 0;

    int ans = INT_MAX;
    for(int i=1;i*i<= n;i++){
        ans = min(ans, 1+solve(n-(i*i)));
    }
    return ans;
}
// recursion + memo
int solve1(int n, vector<int>& dp){
    if( n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for(int i=1;i*i<= n;i++){
        ans = min(ans, 1+solve1(n-(i*i), dp));
    }
    return dp[n] = ans;
}
//tabulation
int solve2(int N){
    vector<int> dp(N+1, 0);

    for(int n=1;n<=N;n++){
        int ans = INT_MAX;
        for(int i=1;i*i<= n;i++){
            ans = min(ans, 1+dp[n-(i*i)]);
        }
        dp[n] = ans;
    }
    return dp[N];
}
int main(){
    int n = 12;
    cout<<solve(n)<<endl;
    //recursion + memo
    vector<int> dp(n+1, -1);
    cout<<solve1(n,dp)<<endl;
    // Bottom up
    cout<<solve2(n)<<endl;
    return 0;
}