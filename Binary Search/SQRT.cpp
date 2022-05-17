/*

Program to find the Square root of the number

Sqaure root of the number is always less that x/2; where x is the number

*/
#include<bits/stdc++.h>
using namespace std;
int squareRoot(int x){
    int start = 0;
    int end = (x/2)+1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        long long int ans = mid*mid;
        if(ans == x)
        {
            return mid;
        }
        if(mid*mid < x && ((mid+1)*(mid+1)) > x){ 
            return mid;
        }
        if(mid*mid > x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    cout<<"Square root of the number is"<<squareRoot(n);
    return 0;
}