// Question is the First and Last element in the Sorted Array
#include<bits/stdc++.h>
using namespace std;
int firstSearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int ans;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2

        if(arr[mid] == target)
        {
            end = mid-1;
            ans = mid;
        }
        if(target <= arr[mid]) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return ans;
}
int lastSearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int ans;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2

        if(arr[mid] == target)
        {
            start = mid+1;
            ans = mid;
        }
        if(target >= arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<"Element is found First at pos "<<firstSearch(arr,n,target)<<endl;
    cout<<"Element is found last at pos "<<lastSearch(arr,n,target);
    return 0;
}