#include <iostream>
using namespace std;

class MyException : public exception
{
private:
    const char* text;

public:
    MyException(const char* s) {
        text = s;
    }
    virtual const char* what() const throw() {
        return text;
    }
};

int main()
{
    try {
        throw MyException("MyException class err :( ");
    }
    catch(MyException& ex) {
        cout<<"err: "<< ex.what()<<endl;
    }

    cout<<"*_*"<<endl;
    return 0;
}