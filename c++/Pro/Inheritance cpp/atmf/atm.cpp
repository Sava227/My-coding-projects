#include <iostream>
using namespace std;

class card {
protected:
    int pin = 123456;
    int sum = 1000;

public:
    void pay(int pin) {
        if (pin != this->pin) return;
        sum -= 150;
        cout << "Sum: " << sum;
    }
};

class ATM : private card {
public:
    void transaction(int pin) {
        pay(pin);
    }
};

int main()
{
    ATM atm;
    atm.transaction(123456);
    return 0;
}