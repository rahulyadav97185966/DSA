#include<bits/stdc++.h>
using namespace std;
class Human{
    protected:
        int age;
        char name;
        int getAge(){
            return this->age;
        }
};

class Male : public Human{
public:
    void fun(){
        cout<<this->age;
    }
    
};
int main(){

    Human h;
    Male m;
    return 0;
}