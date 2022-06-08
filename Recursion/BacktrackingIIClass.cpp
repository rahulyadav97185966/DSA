#include<bits/stdc++.h>
using namespace std;

void Solve(int *arr, int n, vector<vector<int>> &ans, vector<int> &output, int index) {
    if(index >= n){
        ans.push_back(output);
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for(int i=index;i<n;i++){
        if(i > index && arr[i] == arr[i-1]) continue;
        output.push_back(arr[i]);
        Solve(arr,n,ans,output, i+1);
        output.pop_back();
    }
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    // int target;
    // cin>>target;
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;
    sort(arr, arr+n);
    Solve(arr, n, ans,output, index);
    return 0;
}