/* 
Program to find the peak in a mountain array
given the array we need to find the mac element, the array is not in sorted Format
For Example : {0 , 2, 1, 0} ans = 2
*/

#include<bits/stdc++.h>
using namespace std;
int findPeak(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start < end){   // we are not applying thr start <= end cause we don't need to comapre the same element fromt the array
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        if(arr[mid] < arr[mid+1] && mid+1 != n){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Element is found at pos "<<findPeak(arr,n);
    return 0;
}