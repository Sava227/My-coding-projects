#include <iostream>
#include <string>
using namespace std;

class Area{
protected:
    string Name;
public:
    Area(string name):Name(name){}
    string getName()const{return Name;}
    virtual string getPlace()const=0;
    virtual ~Area(){}
};

class Savannah:public Area{
public:
    Savannah(string name):Area(name){}
    string getPlace()const override{return "Саванне";}
};

class Jungle:public Area{
public:
    Jungle(string name):Area(name){}
    string getPlace()const override{return "Джунглях";}
};

int main(){
    Savannah sav1("Лев"),sav2("Носорог"),sav3("Леопард");
    Jungle jung1("Обезьяна"),jung2("Питон"),jung3("Пантера");
    Area* places[]={&sav1,&sav2,&sav3,&jung1,&jung2,&jung3};
    for(int i=0;i<6;i++)
        cout<<places[i]->getName()<<" живёт в "<<places[i]->getPlace()<<endl;
    return 0;
}