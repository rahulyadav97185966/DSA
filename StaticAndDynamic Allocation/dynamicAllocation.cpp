#include<bits/stdc++.h>
using namespace std;
void func1(int **arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main(){
    // Reference variable : it is a reference variable that will assign to same vairble only name changes, For example pointer takes 
    // the 8 byte of space to store but reference varible use the same space 
    // When a reference variable is declare as a reference, it becomes an alternative name for an 
    // existing variable. A varible can e decalred as a reference by putting '&' in the declaration

    int a = 5;
    int& j = a;
    cout<<j<<endl;
    j = 50;
    cout<<"value after "<<a<<" "<<j<<endl;

    // in the for each loop as well we can are using the reference variable
    int arr[] = {1,2,3,4,5};
    for(int &x: arr){  // here we are using th r& cause we are modifying the value present at that address;
        x = x*10;
    }
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<"\n";
    // int *ptr = NULL;
    // int &ref = *ptr;
    // cout<<ref<<"\n";

    // Dynamic int 
    // int n;
    // cin>>n;
    // int* arr1 = new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr1[i];
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr1[i]<<" ";
    // }
    // cout<<"\n";
    // delete []arr1;

    //2d dynamic array
    // int n,m;
    // cin>>n>>m;
    // int **arr1 = new int*[n];
    // for(int i=0;i<n;i++){
    //     arr1[i] = new int[m];
    // }
    // //input
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr1[i][j];
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr1[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n\n";
    // //passing this to the function
    // func1(arr1,n,m);

    // // how to delete these 2d array

    // for(int i=0;i<n;i++){
    //     delete []arr1[i];
    // }
    // delete []arr1;


    // Now Create an array like below (Jagged Array)
    // 1 2 3 4 5
    // 1 2 4
    // 1 2 3 4 
    
    int n,m;
    cin>>n>>m;
    int arr3[m];
    for(int i=0;i<m;i++){
        cin>>arr3[i];
    }
    int **arr2 = new int*[n];
    for(int i=0;i<n;i++){
        arr2[i] = new int[arr3[i]];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<arr3[i];j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<arr3[i];j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<"\n";
    }

    // delete this
    for(int i=0;i<m;i++){
        delete []arr2[i];
    }
    delete []arr2;



    return 0;
}