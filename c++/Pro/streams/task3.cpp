#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout<<"Drawing a generic shape"<<endl;
    }

    //destructor
    virtual ~Shape() {}
};

//rectangle
class rectangle : public Shape {
public:
    void draw() override {
        cout<<"Drawing a rectangle"<<endl;
    }
};

//circle
class circle : public Shape {
public:
    void draw() override {
        cout<<"Drawing a circle"<<endl;
    }
};

//shapes
class shape_container {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void draw_all() {
        for (Shape* shape : shapes) {
            shape->draw(); //call
        }
    }

    ~shape_container() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }
};

int main()
{
    shape_container container;

    container.addShape(new rectangle());
    container.addShape(new circle());
    container.addShape(new rectangle());

    container.draw_all();

    return 0;
}