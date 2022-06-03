#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0] > arr[1])return false;

    bool ans = isSorted(arr+1,size-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<isSorted(arr,n)<<"\n";
    return 0;
}