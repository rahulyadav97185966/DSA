#include <bits/stdc++.h>
using namespace std;
int solve(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    int first = solve(n - a, a, b, c);
    int second = solve(n - b, a, b, c);
    int third = solve(n - c, a, b, c);
    return 1 + max(first, max(second, third));
}
// recursion + memoisation
int solve1(int n, int a, int b, int c, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    int first = solve1(n - a, a, b, c, dp);
    int second = solve1(n - b, a, b, c, dp);
    int third = solve1(n - c, a, b, c, dp);
    return dp[n] = 1 + max(first, max(second, third));
}
//tabulation
int solve2(int n, int a, int b, int c){
    vector<int> dp(n+1, INT_MIN);
    for(int i=0;i<=n;i++){
        int first = dp[i - a];
        int second = dp[i - b];
        int third = dp[i - c];
        return dp[i] = max(first, max(second, third));
    }
    return dp[n];
}
int main()
{
    int n = 17;
    int a = 10, b = 11, c = 3;
    cout << solve(n, a, b, c) << endl;
    // Sovle using Rec+ memo
    vector<int> dp(n + 1, -1);
    cout << solve1(n, a, b, c, dp) << endl;
    //using tabulation
    cout<<solve2(n,a,b,c)<<endl;

    return 0;
}