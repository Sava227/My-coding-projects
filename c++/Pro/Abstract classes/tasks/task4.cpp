#include <iostream>
using namespace std;

class IMathFunc{
public:
    virtual double Function(int a,int b,int x)=0;
    virtual void FunctionName()=0;
    virtual ~IMathFunc(){}
};

class LinearFunction:public IMathFunc{
public:
    double Function(int a, int b, int x)override{
        return a*x+b;
    }

    void FunctionName() override{
        cout<<"Linear dunction y =ax+b"<<endl;
    }
};

class QuadraticFunction:public IMathFunc{
public:
    double Function(int a,int b, int x) override{
        int c=3;
        return a*x*x+b*x+c;
    }

    void FunctionName() override{
        cout<<"Quadratic fnction y=ax*x+bx+c"<<endl;
    }
};

class CubicFunction:public IMathFunc{
public:
    double Function(int a,  int b, int x)override{
        return a*x*x*x+b*x;
    }

    void FunctionName() override{
        cout<<"Cubic fuunction y=ax*x*x+bx"<<endl;
    }
};

int main(){
    int a,b,x;
    cout<<"Enter a,b &x valuus"<<endl;
    cin>>a;
    cin>>b;
    cin>>x;

    IMathFunc* linear =new LinearFunction();
    IMathFunc* quadratic= new QuadraticFunction();
    IMathFunc* cubic=new CubicFunction();
    linear->FunctionName();
    cout<<linear->Function(a,b, x)<<endl;
    quadratic->FunctionName();
    cout<<quadratic->Function(a,b,x)<<endl;
    cubic->FunctionName();
    cout<<cubic->Function(a,b,x)<<endl;
    delete linear;
    delete quadratic;
    delete cubic;

    return 0;
}
