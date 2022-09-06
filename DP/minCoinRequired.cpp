#include <bits/stdc++.h>
using namespace std;
int minCoin(int target, int *arr)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int ans = minCoin(target - arr[i], arr);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
// recursion  + MEMO
int solve(int target, int *arr, vector<int> &dp, int n)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
        return INT_MAX;
    if (dp[target] != -1)
        return dp[target];
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = solve(target - arr[i], arr, dp, n);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return dp[target] = mini;
}
// tabulation
int solve2(int t, int *arr, int n)
{
    vector<int> dp(t + 1, INT_MAX);
    dp[0] = 0;
    for (int target = 1; target <= t; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (target - arr[i] >= 0)
            {
                int ans = dp[target - arr[i]]; // it is possible that it can be negative index
                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[t];
}
int main()
{
    int target = 7;
    int arr[] = {1, 2, 3};
    // recursion
    cout << minCoin(target, arr) << endl;
    // recursion + memo
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp(target + 1, -1);
    cout << solve(target, arr, dp, n) << endl;
    // bottom up
    cout << solve2(target, arr, n) << endl;
}