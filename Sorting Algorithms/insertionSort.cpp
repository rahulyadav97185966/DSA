#include<bits/stdc++.h>
using namespace std;
void insertionSort(int* arr, int n){
    for(int i=1;i<n;i++){
        int value = arr[i];
        int hole = i;
        while(hole >0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    insertionSort(arr,n);
}