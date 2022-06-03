#include<bits/stdc++.h>
using namespace std;

void permutation(string &s, vector<string> &ans, int index) {

    if(index >= s.length()){
        ans.push_back(s);
        return;
    }
    for(int j=index;j<s.length();j++) {
        swap(s[j],s[index]);
        permutation(s,ans,index+1);
        swap(s[j],s[index]);
    }
}

int main() {
    string s;
    cin>>s;
    vector<string> ans;
    int index = 0;
    string output = "";
    permutation(s,ans,index);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    return 0;

}