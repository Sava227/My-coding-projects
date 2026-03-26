#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, a, y;

    cout<<"Put the value of x in: "<<endl;
    if (!(cin >> x)) {
        cout<<"Error!"<<endl;
        return 1;
    }

    cout<<"Please put in the value of a: "<<endl;
    if (!(cin >> a)) {
        cout<<"Error"<<endl;
        return 1;
    }

    y = 10 + sqrt(pow(x, a));

    if (isnan(y)) {
        cout<<"Error! Negative number."<<endl;
    } else {
        cout<<"The result of y= "<<y<<endl;
    }

    return 0;
}
