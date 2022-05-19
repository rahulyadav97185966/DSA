#include<bits/stdc++.h>
using namespace std;
bool isPossible(int * arr, int mid, int n, int k){
    int r = 1;
    int sum = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > mid) return false;
        if(sum+arr[i] > mid){
            r++;
            sum = arr[i];
        }
    }
    if(r <= k) return true;
    return false;
}
int binary_Search(int * arr, int n, int k) {
     int start = 0;
     int sum=0;
     for(int i=0;i<n;i++)sum+=arr[i];
     int end = sum;
     int ans;
     while(start <= end){
         int mid = (start + end)/2;
         if(isPossible(arr,mid,n,k)){
             ans = mid;
             end = mid-1;
         }
         else{
             start = mid +1;
         }
     }
     return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<binary_Search(arr,n,k);
    return 0;
}