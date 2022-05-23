#include<bits/stdc++.h>
using namespace std;

void func1(int **arr, int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }    
}


int main(){
    // Here we are learning 2d array
    // int a = 5;
    // int * p = &a;
    // int **q = &p;
    // cout<<&a; // address  
    // cout<<a; // value = 5
    // //cout<<*a; // error cause this is not pointer
    // cout<<&p; // address of p
    // cout<<p; // address of a cause in p we have stored the address of the a
    // cout<<*p; // value stored at p
    // cout<<"\n\n\n";
    // cout<<&q<<"\n";
    // cout<<q<<endl;
    // cout<<*q<<endl;

    // cout<<"Before"<<q <<endl; 
    // cout<<"Before"<<*q <<endl; 
    // cout<<"Before"<<**q <<endl; 
    // func1(q);
    // cout<<"After"<<q<<endl;
    // cout<<"After"<<*q<<endl;
    // cout<<"After"<<**q<<endl;

    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout<<*ptr;
    // int k[] = {1,2,3,4};
    // cout<<*k;
    // cout<<*(k+0);
    // cout<<*(k+1);
    // cout<<*(k+2);
    // cout<<*(k+3)<<endl;
    // cout<<0[k]<<endl;
    // cout<<sizeof(k);    
    // char ch = 'A';

    // char *p = &ch;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;
    // cout<<*(p+0)<<endl;

    // char arr[] = "this is by sagar";
    // char *p = arr;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;

    // Dynamic Allocation 
    // int n;
    // cin>>n;
    // int *ptr = new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>ptr[i];
    // }
    // for(int i=0;i<n;i++) cout<< ptr[i] <<" ";

    // 2D Dynamic Array 
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n";
    // passing this to the function
    func1(arr,n,m);
    for(int i=0;i<n;i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;
}