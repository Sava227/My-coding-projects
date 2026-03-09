#include <iostream>
#include <string>
using namespace std;

class Parent{
public:
    string sayHello(){return "hel";}
    virtual string getName(){return "oarent";}
    virtual int getAge()=0;
};

class Child:public Parent{
public:
    int getAge()override{return 5;}
    string getName()override{
        cout<<"Parent name: "<<Parent::getName()<<endl;
        return "Child";
    }
};

class Child2:public Parent{
public:
    int getAge()override{return 7;}
    string getName()override{return "Cchild2";}
};

int main(){

    Parent* parent=new Child();
    cout<<parent->getAge()<<endl;
    cout<<parent->getName()<<endl;
    cout<<parent->sayHello()<<endl;

    delete parent;

    Parent* parent2=new Child2();
    cout<<parent2->getAge()<<endl;
    cout<<parent2->getName()<<endl;
    cout<<parent2->sayHello()<<endl;

    delete parent2;
    return 0;
}
