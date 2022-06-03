#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n){
    string v[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n == 0){
        return;
    }
    int digit = n%10;
    int num = n/10;
    sayDigits(num);
    cout<<v[digit]<<" ";


}

int main(){
    int n;
    cin>>n;
    sayDigits(n);
    
    return 0;
}