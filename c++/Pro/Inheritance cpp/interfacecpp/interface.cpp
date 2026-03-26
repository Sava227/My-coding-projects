#include <iostream>
using namespace std;

class Device {
public:
    virtual void turn_on() = 0;
    virtual ~Device() =default;
};

class Laptop : public Device {
public:
    void turn_on() override {
        cout<<"Laptop is on"<<endl;
    }
};
class Computer : public Device {
public:
    void turn_on() override{
        cout<<"Computer is on."<<endl;
    }
};
int main() {
    Laptop laptop;
    Computer computer;
    Device* devices[] = { &laptop, &computer };

    for(Device* d : devices){
        d->turn_on();
    }
    return 0;
}
