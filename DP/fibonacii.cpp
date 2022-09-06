#include<bits/stdc++.h>
using namespace std;
//Recursive Solution
int RecursiveSolution(int n){
    if(n <= 1)
        return n;
    int ans = RecursiveSolution(n-1)+RecursiveSolution(n-2);
    return ans;
}
// Memoization
int memoisationSol(int n, vector<int>& dp){
    if(n <= 1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    int ans = memoisationSol(n-1, dp)+memoisationSol(n-2, dp);
    return dp[n] = ans;
}
//Solution using the tabulation or bottom up approach is
int TabulationSol(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1; 

    for(int i=2;i<=n;i++){
        int ans = dp[i-1]+dp[i-2];
        dp[i] = ans;
    }
    return dp[n];
}
//Solution using space optimization i.e most optimized solution is
int SpaceOpti(int n){

    int prev1 = 1;  // this shows the index 1
    int prev2 = 0; // this shows the index 0
    int current;

    for(int i=2;i<=n;i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1; // or current
}
int main(){

    int n = 6;
    cout<<"Nth fib number using the Recursion is: ";
    cout<<RecursiveSolution(n);
    cout<<"\nNth fib Number using Recursion+Memoisation is: ";
    vector<int> dp(n+1, -1);
    cout<<memoisationSol(n, dp);
    cout<<"\nSolution using the Bottom up (table): ";
    cout<<TabulationSol(n);
    cout<<"\nSpace optimization Solution is: ";
    cout<<SpaceOpti(n);
    return 0;
}