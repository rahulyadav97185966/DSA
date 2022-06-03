#include<bits/stdc++.h>
using namespace std;

void ReverseStr(int i, int j, string &s)
{
    if(i > j) return;

    swap(s[i],s[j]);
    i++;
    j--;
    ReverseStr(i,j,s);
}

int main(){
    string s = "sagar";
    ReverseStr(0,s.length()-1,s);
    cout<<s<<"\n";
    return 0;
}