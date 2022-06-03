#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void SelectionSort(int arr[], int n){
    // cout<<"Array Here is: ";
    // print(arr,n);
    //Base Condition
    if(n == 0 || n == 1){
        return;
    }
    int iMin = 0;
    //cout<<"Minimum element is and it's position is "<<min<<" pos: "<<iMin<<"\n";
    for(int i=1;i<n;i++){
        if(arr[i] < arr[iMin]){
                iMin = i;
        }
    }
    swap(arr[0], arr[iMin]);
    SelectionSort(arr+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SelectionSort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}