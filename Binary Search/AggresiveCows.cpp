#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPossible(ll arr[],ll n, ll mid,ll cows){

    ll cows_req=1;
    ll prev_val = arr[0];
    for(ll i=0;i<n;i++){
        if(arr[i]-prev_val >= mid){
            prev_val = arr[i];
            cows_req++;
        }
        if(cows_req == cows)return true;
    }
    return false;
}

ll Solution(ll arr[],ll n, ll cows){

    sort(arr,arr+n);
    ll s = 0;
    ll e = arr[n-1];
    ll ans;
    while(s <= e){

        ll mid = (s+e)/2;

        if(isPossible(arr,n,mid,cows)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll cows;
    cin>>cows;
    cout<<Solution(arr,n,cows);
    return 0;
}
