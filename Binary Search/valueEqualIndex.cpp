// Program to find the value is equal to index 

// Constrainst : only single value is present with index == value

#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        if(arr[mid] == mid)
        {
            return mid;
        }
        if(arr[mid] > mid) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Element is found at pos "<<binarySearch(arr,n);
    return 0;
}