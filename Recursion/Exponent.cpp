#include<bits/stdc++.h>
using namespace std;

int exponent(int a, int b){
    //Base Case
    if(b == 0)return 1;
    if(b == 1) return a;

    //Recursive Call
    int ans = exponent(a,b/2);

    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<exponent(a,b);
    return 0;
}