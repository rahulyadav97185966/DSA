
// ECO SPOj

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isPossible(ll arr[], ll mid, ll target, ll n)
{

    ll sum = 0;
    for(ll i=0;i<n;i++){
        if(arr[i]-mid > 0)
            sum+=(arr[i]-mid);
    }
    if(sum >= target)
        return true;
    else
        return false;

}

ll binary_search(ll arr[],ll start, ll end, ll target, ll n)
{
    ll pos_sol = -1;
    while(start <= end){
        ll mid = (start+end)/2;
        if(isPossible(arr,mid,target,n))
        {
            pos_sol = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return pos_sol;
}

int main()
{

    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll max_val = arr[n-1];
    ll start = 0;
    ll end = max_val;
    cout<<binary_search(arr,start,end, m,n);

    return 0;
}
