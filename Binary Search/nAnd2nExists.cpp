/*
Program to find the n and it's double exits in array or not 
-> Given array maybe not be in sorted form so we need to sort it so time Commple . O(NlonN);
*/
#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int start, int end, int target){
    // int start = 0;
    // int end = n-1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2

        if(arr[mid] == target)
        {
            return true;
        }
        if(target > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return false;
}
bool checkDouble(int arr[], int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int key = arr[i];
        if(arr[i] >= 0 && i != n-1){
            if(binarySearch(arr,i+1,n,key*2)){      // arr, start, end, value double we are passing
                return true;
            }
        }
        else if(arr[i] < 0 && arr[i]%2 == 0){
            if(binarySearch(arr,i+1,n,key/2)) {  // since we are searching the for negative element we will pass half of the number
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<checkDouble(arr, n);
    return 0;
}