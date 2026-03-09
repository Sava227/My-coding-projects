//What will happen if we run this code without virtualizing class A? - Name of class: A
//What will happen if we will virtualize class A? - Name of class: B
#include<iostream>
using namespace std;
class A{
public:
    virtual char getName(){
        return 'A';
    }
};

class B: public A{
public:
    char getName(){
        return 'B';
    }
};

int main() {
    B b;
    A& a = b;
    cout<<"Name of class: "<<a.getName()<<'\n';
    return 0;
}