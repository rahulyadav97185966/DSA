#include<bits/stdc++.h>
using namespace std;
class Human{
public:   // this is called as access specifiers
    char ch;
    double dh1;
    int a;
    int b;
    char ah;
    int c;
    double dh;
    

};
int main(){

    Human h;  // this is a static object. object is an instance of the clss
    // Class don't take memory when it creates when object created the memory is created.
    cout<<sizeof(h);
    Human *h1 = new Human();
    cout<<"\nthis is "<<sizeof(h1);
    h1->a;
    delete h1;
    return 0;
}