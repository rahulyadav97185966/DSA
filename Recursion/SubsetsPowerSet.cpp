#include<bits/stdc++.h>
using namespace std;

void PowerSet(int *arr, int index, vector<int> output, vector<vector<int>>& ans, int n) {
    //base case
    if(index >= n){
        ans.push_back(output);
        return ;
    }
    //exclude the element
    PowerSet(arr,index+1,output,ans,n);
    //include the element
    int element = arr[index];
    output.push_back(element);
    PowerSet(arr,index+1,output,ans,n);
}


int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index = 0;
    vector<int> output; 
    vector<vector<int>> ans;
    PowerSet(arr, index, output, ans,n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }
    delete []arr;
    return 0;
}