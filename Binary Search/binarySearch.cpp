#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2

        if(arr[mid] == target)
        {
            return mid;
        }
        if(target > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
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
    int target;
    cin>>target;
    cout<<"Element is found at pos "<<binarySearch(arr,n,target);
    return 0;
}