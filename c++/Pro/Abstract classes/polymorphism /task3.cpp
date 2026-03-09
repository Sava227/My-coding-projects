#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual string getName() const = 0;
    virtual string getFormula() const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    string getName() const override {
        return "Circle";
    }
    string getFormula() const override {
        return "S = Pi * r^2";
    }
    double getArea() const override {
        return M_PI * r * r;
    }
};
class Triangle : public Shape {
    double a, b;
public:
    Triangle(double base, double height) : a(base), b(height) {}
    string getName() const override {
        return "Triangle";
    }
    string getFormula() const override {
        return "S = (a * b) / 2";
    }
    double getArea() const override {
        return (a * b) / 2;
    }
};
class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double width, double height) : a(width), b(height) {}
    string getName() const override {
        return "Rectangle";
    }
    string getFormula() const override {
        return "S = a * b";
    }
    double getArea() const override {
        return a * b;
    }
};

int main() {
    Circle c(6);
    Triangle t(6, 3);
    Rectangle r(6, 3);
    Shape* shapes[] = { &c, &t, &r };
    for (int i = 0; i < 3; i++) {
        cout<<shapes[i]->getName()<<endl;
        cout<<shapes[i]->getFormula()<<endl;
        cout<<"Area="<<shapes[i]->getArea()<<endl;
    }
    return 0;
}