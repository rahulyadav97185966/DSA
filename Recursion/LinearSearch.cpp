#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int *arr, int n,int k){
    if(n == 0)return false;
    if(n == 1 && arr[0] == k) return true;

    if(arr[0] == k){
        return true;
    }
    else{
        LinearSearch(arr+1,n-1,k);
    }

}


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<LinearSearch(arr,n,k)<<"\n";
    return 0;
}