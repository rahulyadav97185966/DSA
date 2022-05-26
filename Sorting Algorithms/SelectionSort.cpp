#include<bits/stdc++.h>
using namespace std;
void SelectionSort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int iMin = i;
        int min_latest;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[iMin]){
                iMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;

        // Or We can write swap(arr[iMin], arr[min_latest]);
        // swap(arr[iMin],arr[min_latest]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SelectionSort(arr,n);
    return 0;
}