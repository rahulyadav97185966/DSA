#include<bits/stdc++.h>
using namespace std;

int divideMerge(int arr[], int arr2[], int n, int m){
    vector<int> v;
    int j=0;
    int i=0;
    while(i != n || j != m){
        if(arr[i] <= arr[j]){
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr2[j]);
            j++;
        }
    }
    while(i != n){
        v.push_back(arr[i++]);
    }
    while(j != m){
        v.push_back(arr[j++]);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;

}

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    cout<<divideMerge(arr,arr2,n,m);
    return 0;
}