#include<bits/stdc++.h>
using namespace std;

int Factorial(int n){
    //base condition
    if(n == 1){
        return 1;
    }
    //recursive call
    return n*Factorial(n-1);
}

void Counting(int n){
    if(n < 1){
        return;
    }
    return Counting(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cin>>n;
    //cout<<"factorial is : "<<Factorial(n)<<"\n";
    Counting(n);
    return 0;
}