/* 
Program to find the pivot element in the array.

Pivot element is that element after which the element is smaller than that, Next Element in smaller

For Example 4, 5, 6, 1, 2, 3 : In this case the pivot element is 6 since next element is smaller than that element 
*/

#include<bits/stdc++.h>
using namespace std;
int pivotSearch(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        
        if(arr[mid] > arr[mid+1] && mid+1 != n){
            return mid;
        }
        if(arr[mid] < arr[mid-1] && mid-1 >= 0) {
            return mid-1;
        }

        if(arr[mid] > arr[0]){
            start = mid+1;
        }
        else{
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
    cout<<"Element is found at pos "<<pivotSearch(arr,n);
    return 0;
}