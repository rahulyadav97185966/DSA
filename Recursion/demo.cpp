#include<bits/stdc++.h>
using namespace std;
void minCost(string s,int size, string *arr,int *cost,vector<int> &ans,string &output,int index, int cost1) {
    if(output == s){
        ans.push_back(cost1);
        return;
    }
    if(output.length() > s.length() || index >= size){
        return;
    }

    //exclude
    minCost(s,size,arr,cost,ans,output, index+1, cost1);
    //include
     output += arr[index];
     minCost(s,size,arr,cost,ans,output, index, cost1+cost[index]);
     output.pop_back();
}
int main()
{
    string s = "lockdown";
    int size = 4;
    string arr[] = {"lock", "down", "lo", "ck"};
    int cost[] = {50,50,5,5};
    vector<int> ans;
    string output = "";
    int index = 0;
    minCost(s,size,arr,cost,ans,output, index, 0); 
    if(ans.size() < 1){
        cout<<"-1"<<"\n";
    }
    else{
        sort(ans.begin(), ans.end());
        cout<<"ans is: "<<ans[0]<<"\n";
    }
}