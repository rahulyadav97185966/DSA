#include<bits/stdc++.h>
using namespace std;

int Merge(int *arr, int s, int e) {
    int ans = 0;

    int mid = (s+e) /2;
    //give length to to array
    int len1 = mid-s+1;
    int len2 = e-mid;

    //create left and right array
    int *left = new int[len1];
    int *right = new int[len2];

    //insert element into it
    int k = s;
    for(int i=0;i<len1;i++){
        left[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0;i<len2;i++){
        right[i] = arr[k++];
    }

    //merge two arrays using sorting
    int i=0,j=0;
    k = s;
    while(i < len1 && j < len2) {
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }
        else{
            ans += (len1-i);
            arr[k++] = right[j++];
        }
    } 
    while(i < len1) {
        arr[k++] = left[i++];
    }
    while(i < len2) {
        arr[k++] = right[j++];
    }
    return ans;
}

int CountInversion(int *arr, int s, int e){

    int rev = 0;
    if(e > s){
        int mid = (s+e)/2;
        rev += CountInversion(arr,s,mid);
        rev += CountInversion(arr,mid+1,e);
        rev += Merge(arr,s,e);
    }
    return rev;

}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<CountInversion(arr,0,n-1);
    delete []arr;
    return 0;
}