#include<bits/stdc++.h>
using namespace std;

int SumArray(int *arr, int size){
    
    if(size == 0) return 0;
    if(size == 1) return arr[0];

    int remaining = SumArray(arr+1,size-1);
    int sum = arr[0] + remaining;
    return sum;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<SumArray(arr,n)<<"\n";
    return 0;
}