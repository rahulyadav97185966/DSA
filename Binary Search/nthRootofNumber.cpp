#include<bits/stdc++.h>
using namespace std;

int BinarySolution(int start, int end, int n, int m) {

    while(start <= end)
    {
        int mid = (start+end)/2;
        long long int  power = pow(mid,n);
        if(power == m){
            return mid;
        }
        if(power > m){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int start = 0;
    int end = m;
    cout<<BinarySolution(start, end, n, m);
    return 0;
}
