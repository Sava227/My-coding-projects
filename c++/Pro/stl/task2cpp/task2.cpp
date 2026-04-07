#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    double engine_volume;

public:
    Car(string b, string m, int y, double e) {
        brand = b;
        model = m;
        year = y;
        engine_volume = e;
    }

    string getBrand() const {
        return brand;
    }

    void print() const {
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Engine volume: "<<engine_volume<<endl;
    }
};

//removing
void removeCar(stack<Car>& car_stack, const string& brand) {
    stack<Car> temp;                //creaying the temporary stack

    while (!car_stack.empty()) {     //sorting
        if (car_stack.top().getBrand() != brand) {
            temp.push(car_stack.top());  //upper
        }
        car_stack.pop();        //tale away
    }

    //retunr
    while (!temp.empty()) {
        car_stack.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<Car> car_stack;

    //add cars in stack
    car_stack.push(Car("Toyota", "camry", 2020, 2.5));
    car_stack.push(Car("BMW", "X5", 2021, 3.0));
    car_stack.push(Car("Audi", "A6", 2019, 2.0));

    cout<<"Before removal:"<<endl;

    //print with copying
    stack<Car> temp = car_stack;
    while (!temp.empty()) {
        temp.top().print();
        temp.pop();
    }

    //delete
    cout<<"Removing BMW..."<<endl;
    removeCar(car_stack, "BMW");

    cout<<"After removal:"<<endl;

    //print
    temp = car_stack;
    while (!temp.empty()) {
        temp.top().print();
        temp.pop();
    }

    return 0;
}