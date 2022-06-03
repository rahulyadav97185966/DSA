#include<bits/stdc++.h>
using namespace std;

bool PalindromeStr(int i, int j, string &s)
{
    if(i > j) return true;

    if(s[i] == s[j]){
        i++;
        j--;
        return PalindromeStr(i,j,s);
    }
    else{
        return false;
    }
}

int main(){
    string s = "babbab";
    cout<<PalindromeStr(0,s.length()-1,s)<<"\n";
    //cout<<s<<"\n";
    return 0;
}