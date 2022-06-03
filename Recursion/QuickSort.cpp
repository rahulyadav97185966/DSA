#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end) {

    int pivot = arr[start];
    int cnt = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i] <= pivot) {
            cnt++;
        }
    }    
    int pivotIndex = start + cnt;
    swap(arr[start], arr[pivotIndex]);
    //Left and right part handle here
    int i=start,j=end;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void QuickSort(int *arr, int start, int end) {
    if(start >= end) return;
    int j = partition(arr,start,end);
    QuickSort(arr,start,j-1);
    QuickSort(arr,j+1,end);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete []arr;
    return 0;
}