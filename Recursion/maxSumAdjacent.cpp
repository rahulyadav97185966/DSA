#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr, int index, int ans, int &maxi){
    //base case
    if(index >= arr.size()){
        maxi = max(maxi, ans);
        return;
    }
    //include
    solve(arr,index+2,ans+arr[index],maxi);
    //exclude
    solve(arr,index+1,ans,maxi);
}
int main(){
    vector<int> arr = {2,1,4,9};
    int index = 0;
    int ans = 0;
    int maxi = INT_MIN;
    solve(arr, index, ans, maxi);
    cout<<maxi<<endl;
    return 0;
}