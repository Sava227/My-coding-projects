#include <iostream>
#include <vector>
#include <exception>
using namespace std;

int main() {
    try {
        vector<int> v(10);          //create the vector
        for (int i=0;i<10;++i) {     //fill the vector with numbers
            v[i]= i *10;
        }
        cout<<"accessing element at index 15..."<<endl;
        cout<<v.at(15)<<endl;

    } catch(const exception& e) {
        cout<<"out f range error: "<<e.what()<<endl;
    }

    return 0;
}