#include<iostream>
#include<stdexcept>
using namespace std;

void func(int a)
{
    if (a == 0)
        throw std::runtime_error("Error: Null argument");
}

int main()
{
    int a =0;
    try
    {
        func(a);
    }
    catch (const exception& err)
    {
        cout<<err.what()<<endl;
    }
    cout<<"the end"<<endl;
    return 0;
}