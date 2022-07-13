#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 5;
    // values of A
    cout<<a<<endl;
    cout<<&a<<endl;
    int* ptr = &a;  // creation of a pointer
    //Printing thr ptr
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;

    // Pointers to Char datatype
    char ch = 'a';
    cout<<"character printing "<<ch<<endl;
    cout<<&ch<<endl;
    char* ptr1 = &ch;
    cout<<"pointer printing is "<<ptr1<<endl;
    cout<<&ptr1<<endl;
    cout<<*ptr1<<endl;

    // POinters to String Datatype
    string s = "this is sagar";
    cout<<s<<endl;
    string* ptr2 = &s;
    cout<<ptr2<<endl;
    cout<<&ptr2<<endl;
    cout<<*ptr2<<endl;

    //Poniters to the CharArray

    char str[] = "THIS IS SAGAR";
    cout<<str<<endl;
    char*  ptr3 = str;
    cout<<ptr3<<endl;
    cout<<&ptr3<<endl;
    cout<<*ptr3<<endl; // this is equal to str[0] or [0]str or *(str + 0)
    cout<<*(ptr3 + 0)<<endl;  //  we can write this for every element
    cout<<str[0]<<endl;
    

    // Pointers to Array

    int arr[] = {1,2,3,4};
    cout<<"Printing the array"<<arr<<endl; // this will print the base address of the array
    cout<<"printing the array"<<&arr<<endl;
    cout<<*arr<<endl;
    int *ptr4 = arr;
    cout<<"printing pointer"<<ptr<<endl;
    cout<<&ptr4<<endl;
    cout<<*ptr4<<endl;
    cout<<*(ptr4 + 0)<<endl;
    cout<<"\n\n";
    cout<<"read beloew"<<endl;
    cout<<*ptr+2<<endl;
    cout<<*ptr+1<<endl;
    cout<<*ptr+0<<endl;
    cout<<"this is arr"<<*(arr + 0)<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(arr)<<endl;
    cout<<0[arr]<<endl;
    cout<<"\n\n";
    // 2d Pointers

    int x = 6;
    int* ptr5 = &x;
    int** ptr6 = &ptr5;
    // cout<<x<<endl;
    // cout<<&x<<endl;
    // cout<<ptr5<<endl;
    // cout<<&ptr5<<endl;
    // cout<<*ptr5<<endl;
    // cout<<ptr6<<endl;
    // cout<<&ptr6<<endl;
    // cout<<*ptr6<<endl;
    // cout<<**ptr6<<endl;
    return 0;
}