#include<bits/stdc++.h>
using namespace std;

void SubsetSum(int *arr, int index, vector<int>& ans, int sum, int n) {

    if(index >= n) {
        ans.push_back(sum);
        return ;
    }
    //exclude
    SubsetSum(arr,index+1,ans,sum,n);
    //include
    sum+=arr[index];
    SubsetSum(arr,index+1,ans,sum,n);
}


int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index = 0;
    vector<int> ans;
    int sum = 0;
    SubsetSum(arr,index,ans,sum,n);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    delete []arr;
    return 0;
}