#include <iostream>
using namespace std;
class A
{
public:
    virtual ~A()
    {
        cout<<"destructor A"<<endl;
    }
};

class B : public A
{
private:
    int* arr;

public:
    B(int length)
    {
        arr =new int[length];
        cout<<"B constructor"<<length<<" ints\n";
    }
    ~B()
    {
        cout<<"destructor B"<<endl;
        delete[] arr;
    }
};

int main()
{
    B* child =new B(5);
    A* parent= child;
}