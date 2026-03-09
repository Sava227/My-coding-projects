#include <iostream>
#include <string>
using namespace std;

class Programmer {
public:
    virtual string getLevel() const = 0;
    virtual string getExperienceGain() const = 0;
    virtual int getExperiencePoints() const = 0;
    virtual ~Programmer() {}
};

class Student : public Programmer {
public:
    string getLevel() const override {
        return "student";
    }
    string getExperienceGain() const override {
        return "0";
    }
    int getExperiencePoints() const override {
        return 0;
    }
};
class Intern : public Programmer {
public:
    string getLevel() const override {
        return "intern";
    }
    string getExperienceGain() const override {
        return "+1";
    }
    int getExperiencePoints() const override {
        return 1;
    }
};

class Junior : public Programmer {
public:
    string getLevel() const override {
        return "junior";
    }
    string getExperienceGain() const override {
        return "+2";
    }
    int getExperiencePoints() const override {
        return 2;
    }
};

class Senior : public Programmer {
public:
    string getLevel() const override {
        return "senior";
    }
    string getExperienceGain() const override{
        return "+5";
    }
    int getExperiencePoints() const override {
        return 5;
    }
};

int main() {
    Student s;
    Intern i;
    Junior j;
    Senior sen;
    Programmer* levels[] = { &s, &i, &j, &sen };

    for (int k = 0; k < 4; k++) {
        cout<<levels[k]->getLevel()<<endl;
        cout<<"experience gain:"<<levels[k]->getExperienceGain()<<endl;
        cout<<"points:"<<levels[k]->getExperiencePoints()<<endl;
    }

    return 0;
}