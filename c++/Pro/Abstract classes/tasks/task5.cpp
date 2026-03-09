#include <iostream>
using namespace std;
class IRecipe {
public:
    virtual const char* getRecipe() = 0;
    virtual ~IRecipe() {}
};
class Restaurant1 final : public IRecipe {
public:
    const char* getRecipe() final override {
        return "salmon soup with cream";
    }
};
class Restaurant2 :public IRecipe {
public:
    const char* getRecipe() override {
        return "salmon soup with cream, carrot and onion";
    }
};
int main() {
    IRecipe* res=new Restaurant2();
    cout<<res->getRecipe()<<endl;
}