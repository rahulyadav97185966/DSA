#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n){
    //Base Condition
    if(n == 0 || n == 1) return;

    //solve one case
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);  // largest element to end
        }
    }
    BubbleSort(arr, n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BubbleSort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}