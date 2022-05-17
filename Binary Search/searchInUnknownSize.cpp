/*
Program to find the element in the sorted array of unknown size
So basically We don't know the size of the array.
*/

#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int start, int end, int target){
    
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

int searchSpace(int arr[], int n, int target){

    int s = 0;
    int e = 1;
    int val = arr[0];
    while(val < target){
        s = e;
        e = e*2;
        val = arr[e];
    }
    return binarySearch(arr,s, e, target);
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
    cout<<"Element is found at pos "<<searchSpace(arr,n,target);
    return 0;
}