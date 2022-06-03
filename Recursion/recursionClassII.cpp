#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amount, int currentIndex) {
    if(amount == 0){
        return 1;
    }
    if(amount < 0){
        return 0;
    }
    int ways = 0;
    for(int i=currentIndex;i<n;i++){
        ways += coinChange(coins,n,amount-coins[i],i);
    }
    return ways;
}

int optimalStrategy(int arr[], int i, int j){
    if(i > j){
        return 0;
    }
    int choice1 = arr[i]+min(optimalStrategy(arr,i+2,j), optimalStrategy(arr,i+1,j-1));
    int choice2 = arr[j]+min(optimalStrategy(arr,i+1,j-1), optimalStrategy(arr,i,j-2));
    int ans = max(choice1, choice2);
    return ans;
}

bool SubsetSum(int arr[],int n, int sum, int current_index){
    
    if(sum == 0){
        return true;
    }
    if( sum < 0){
        return false;
    }
    for(int i=current_index;i<n-1;i++){
        return SubsetSum(arr,n,sum-arr[i],current_index+1);
    }
}

int main(){
    // int coins[] = {1,2};
    // int amount = 4;
    // int n = 2;
    // cout<<"the Total possible solution is: "<<coinChange(coins, n, amount, 0);

   // int arr[] = {20,30,2,2,2,10};
//    int arr[] = {5,3,7,10};
//     int i=0;
//     int j=3;
//     cout<<"the ans is: "<<optimalStrategy(arr,i,j);
    int arr[] = {3,34, 4,12,5,2};
    int sum=9;
    cout<<SubsetSum(arr,6,sum, 0)<<endl;
    return 0;
}