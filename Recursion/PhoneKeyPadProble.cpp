#include<bits/stdc++.h>
using namespace std;

void phoneKeypad(string &s, vector<string> &ans, int index, string &output, string mapping[]) {

    if(index >= s.length()) {
          ans.push_back(output);
          return ;  
    }
    int number = s[index] - '0';
    string val = mapping[number];

    for(int i=0;i<val.length();i++) {
        output.push_back(val[i]);
        phoneKeypad(s,ans,index+1,output, mapping);
        output.pop_back();
    }

}


int main() {

    string s;
    cin>>s;
    vector<string> ans;
    int index = 0;
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    phoneKeypad(s,ans,index,output,mapping);
    cout<<"The ans is \n";
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}