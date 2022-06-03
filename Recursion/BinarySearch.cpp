#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int *arr,int k,int s, int e){

    //Base condn
    if(s > e)return false;

    int mid = (s+e)/2;
    if(arr[mid] == k)return true;

    if(arr[mid] < k){
        BinarySearch(arr,k,mid+1,e);
    }
    else{
        BinarySearch(arr,k,s,mid);
    }
}


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<BinarySearch(arr,k, 0, n-1)<<"\n";
    return 0;
}