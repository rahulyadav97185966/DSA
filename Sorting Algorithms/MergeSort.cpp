#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[], int begin, int mid, int end){

    int left_arr_size = mid-begin+1;
    int right_arr_size = end-mid;

    // Create temp array
    int* left = new int[left_arr_size];
    int* right = new int[right_arr_size];

    for(int i=0;i<left_arr_size;i++){
        left[i] = arr[begin + i];
    }
    for(int i=0;i<left_arr_size;i++)cout<<left[i]<<" ";
    cout<<"\n";
    for(int j=0;j<right_arr_size;j++){
        right[j] = arr[mid+1+j];
    }
    for(int i=0;i<right_arr_size;i++)cout<<right[i]<<" ";
    cout<<"\n";
    int i,j = 0;
    int k=begin;
    while(i<left_arr_size && j < right_arr_size){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left_arr_size){
        arr[k] = left[i];
        i++;k++;
    }
    while(j < right_arr_size){
        arr[k] = right[j];
        j++;k++;
    }
}

void MergeSort(int arr[],int start, int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr,mid+1, end);
    Merge(arr,start, mid, end);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}