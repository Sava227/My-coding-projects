#include<iostream>
#include<cmath>
using namespace std;

enum error {OK, LN, SQRT};  //named constant short version :)

int main()
{
    double x;
    cout<<"Please enter the x value: "<<endl;
    cin>>x;

    try
    {
        if (x <= 0) throw LN;
        double l = log(x);
        if (10 -l < 0) throw SQRT;
        cout<<"ur result=" <<sqrt(10 - l)<<endl;
    }
    catch (error e)
    {
        switch (e)
        {
        case LN: cout<<"logarythm is undefined :( "<<endl; break;
        case SQRT: cout<<"the square root is indefined :("<<endl; break;
        }
    }

    cout<<"*_*"<<endl;
    return 0;
}