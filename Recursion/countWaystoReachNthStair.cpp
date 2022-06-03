#include<bits/stdc++.h>
using namespace std;

int WaysToReach(int n){
    //base case
    if(n == 0)return 1;
    int ans = 0;
    //recursive relation
    if(n-1 >= 0 )
        ans += WaysToReach(n-1);
    if(n-2 >= 0)
        ans += WaysToReach(n-2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<WaysToReach(n);

    return 0;
}