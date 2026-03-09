#include <iostream>
#include <string>
using namespace std;
class Language {
public:
    virtual string getLanguage() const = 0;

    virtual ~Language() = default;
};§
class English :public Language {
public:
    string getLanguage() const override {
        return "english language";
    }
};
class Deutsch : public Language {
public:
    string getLanguage() const override {
        return "deutsche Sprache";
    }
};
class Espanol : public Language {
public:
    string getLanguage() const override {
        return "idioma Espanol";
    }
};

int main() {
    English eng;
    Deutsch deu;
    Espanol esp;

    Language& l1 = eng;
    Language& l2 = deu;
    Language& l3 = esp;

    cout<<l1.getLanguage()<<endl;
    cout<<l2.getLanguage()<<endl;
    cout<<l3.getLanguage()<<endl;
    return 0;
}