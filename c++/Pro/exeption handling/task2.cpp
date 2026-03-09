#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a;
    double b;
    double x;

    cout<<"Enter the a value: "<<endl;
    cin>>a;
    cout<<"Enter the b value: "<<endl;
    cin>>b;
    cout<<"Enter the x value: "<<endl;
    cin>>x;

    double argument = a * x + b;

    try
    {
        if (argument < 0) {
            throw "Error: square root of negative number";
        }
        double result = sqrt(argument);
        cout<<"Result: "<<result<<endl;
    }

    catch (const char* msg) {
    cout<<"exception caught: "<<msg<<endl;
}
    return 0;
}