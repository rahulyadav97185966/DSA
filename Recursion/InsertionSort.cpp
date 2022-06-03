#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void InsertionSort(int arr[], int n){
    // cout<<"Array Here is: ";
    // print(arr,n);
    //Base Condition
    if(n<=1){
        return;
    }

    InsertionSort(arr, n-1);
    int nth = arr[n-1];
    int j = n-2;
    while(j>=0 && arr[j] > nth){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = nth;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}