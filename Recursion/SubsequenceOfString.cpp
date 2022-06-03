#include<bits/stdc++.h>
using namespace std;

void Subsequence(string s, int index, int n, vector<string>& ans, string substr) {
    if(index >= n) {
        ans.push_back(substr);
        return ;
    }
    //exclude the element
    Subsequence(s,index+1,n,ans,substr);
    //include the element
    substr += s[index];
    Subsequence(s,index+1,n,ans,substr);
}

int main(){
    string s;
    cin>>s;
    int index = 0;
    int n = s.length();
    vector<string> ans;
    string sub = "";
    Subsequence(s,index,n,ans,sub);
    cout<<"the size of the vector is : "<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}