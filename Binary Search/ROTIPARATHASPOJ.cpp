#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int r, int p, int mid)
{
    int ans = 0;
    for(int i=0;i<r;i++){
        int time = mid;
        int k = 1;
        int count=0;
        while(time > 0){
            time = time - k*arr[i];
            if(time >= 0)
                count++;
                k++;
        }
        ans += count;
    }
    if(ans < p)
        return false;
    return true;
}

int searchSpace(int arr[], int r, int p){

    int start = 0;
    int end = arr[0] * (p * (p+1))/2;
    int ans = 0;
    while(start <= end){
        int mid = (start + end)/2;
        if(isPossible(arr, r, p, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int r;
        cin>>r;
        int arrRank[r];
        for(int i=0;i<r;i++){
            cin>>arrRank[i];
        }
        cout<<searchSpace(arrRank, r, p);

    }

    return 0;
}