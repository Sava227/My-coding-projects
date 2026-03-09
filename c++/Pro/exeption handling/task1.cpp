#include<iostream>
#include<string>
using namespace std;

class divisionbyzero
{
    private:
        string message;
    public:
        divisionbyzero() : message("ERROR! Division by zero is not allowed") {}

    cont string &whats() const
        {
            return message;
        }
};

int main()
{
    double x;
    double y;

    cout<<"Please enter the x value = "<<endl;
    cout<<"Please enter the y value  = "<<endl;              //Please do not enter the number with the , instead use .
    cin>>x>>" / ">>y>>endl;

    try
    {
        if (y == 0.0)
        {
            throw divisionbyzero();
        }
        cout<<"The result of your division is = "<<x/y<<endl;
    }

    catch (const exeption& e)
    {
        cout<<e.what()<<endl;
    }
}