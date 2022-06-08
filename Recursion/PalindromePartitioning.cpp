#include<bits/stdc++.h>
using namespace std;
bool isPlaindrome(string s1) {
    string s2 = "";
    for(int i=s1.length()-1;i>=0;i--){
        s2 += s1[i];
    }   
    return (s1==s2);
}
void PalindromePartitioning(string s, int index, vector<vector<string>> &ans, vector<string> output, string temp) {

    if(index >= s.length()){
        cout<<"the output is"<<endl;
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        ans.push_back(output);
        return;
    }

    for(int i = index;i<s.length();i++){
        temp += s[i];
        if(isPlaindrome(temp)){
            output.push_back(temp);
            PalindromePartitioning(s,i+1,ans,output,"");
            output.pop_back();
        }
        else{
            continue;
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<vector<string>> ans;
    vector<string> output;
    string temp = "";
    PalindromePartitioning(s,0, ans, output,temp);
    return 0;
}