#include<bits/stdc++.h>
using namespace std;
bool isPossible(int pages[], int n, int m, int mid){
    int k = 1;
    int sum = pages[0];
    for(int i=1;i<n;i++){
        if(pages[i] > mid) return false;
        if(sum+pages[i] > mid){
            k++;
            sum = pages[i];
        }
    }
    if(k <= m) return true;
    return false;
}
int searchSpace(int pages[], int n, int m){
    int start = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += pages[i];
    }
    int end = sum;
    int ans;
    while(start <= end){
        int mid = (start+end)/2;
        if(isPossible(pages,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int pages[n];
    for(int i=0;i<n;i++)cin>>pages[i];
    int m;
    cin>>m;
    cout<<searchSpace(pages,n,m);
    return 0;
}