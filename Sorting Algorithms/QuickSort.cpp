#include<bits/stdc++.h>
using namespace std;

int Partition(int* arr, int start, int end){
    int pivot = arr[end];
    int partitionIndex = start;
    for(int i=start;i<end;i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[end]);
    return partitionIndex;
}

void QuickSort(int* arr, int start, int end){
    if(start < end) {
        int partitionIndex = Partition(arr, start, end); // Calling the partition
        QuickSort(arr, start, partitionIndex-1);
        QuickSort(arr, partitionIndex+1, end);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    QuickSort(arr, 0, n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}