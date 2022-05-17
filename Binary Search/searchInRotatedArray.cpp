/* 
Program to Search element in rotated Array.

Pivot element is that element after which the element is smaller than that, Next Element in smaller

For Example 4, 5, 6, 1, 2, 3 : In this case the pivot element is 6 since next element is smaller than that element 

Now we need to find the element in this so first find the peak and then divide array into two and apply binary search on it.

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

int binarySearch(int arr[], int s,int n, int target){
    int start = s;
    int end = n;
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
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int elem;
    cin>>elem; // this we need to search in the array
    int k = pivotSearch(arr,n);
    cout<<"Pivot element is found at pos "<<k<<endl;
    int r = binarySearch(arr,0,k,elem);
    if(r != -1){
        cout<<"Element is found at pos: "<<r<<endl;
    }
    else{
        int secondhalf = binarySearch(arr,k+1,n-1,elem);
        if(secondhalf != -1){
            cout<<"element is found at pos: "<<secondhalf<<endl;
        }
        else{
            cout<<"Element is no present in the array"<<endl;
        }
    }
    return 0;
}