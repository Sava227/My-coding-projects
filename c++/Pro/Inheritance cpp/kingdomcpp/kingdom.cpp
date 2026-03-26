#include <iostream>
#include <string>
using namespace std;

class Farmer {
protected:
    int health;

public:
    explicit Farmer(int h = 10) : health(h) {}
    int getHealth() const { return health; }
};

class Lord : public Farmer {
protected:
    int wealth;

public:
    Lord(int h=10, int w = 100) : Farmer(h), wealth(w) {}
    int getWealth() const { return wealth; }
};

class Knight : public Farmer {
protected:
    int power;

public:
    Knight(int h = 10, int p = 20) : Farmer(h), power(p) {}
    int getPower() const { return power; }
};

class King : public Lord, public Knight {
    int control;

public:
    King(int h = 10, int w = 100, int p = 20, int c = 50)
        : Lord(h, w), Knight(h, p), control(c) {}

    void print() const {
        cout<<"Король\n";
        cout<<"Власть: "<<control<<"\n";
        cout<<"Сила: "<<getPower()<<"\n";
        cout<<"Богатство: "<<getWealth()<<"\n";
        cout<<"Здоровье (через Lord): "<<Lord::getHealth()<<"\n";
        cout<<"Здоровье (через Knight): "<<Knight::getHealth()<<"\n";
    }
};

int main() {
    King king;
    king.print();
    return 0;
}
