#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

string readFromFile(const string& name) {
    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open(name);
    string line;
    getline(file, line);
    file.close();
    return line;
}

int main() {
    try {
        cout<<"trying to read missing f"<<endl;
        readFromFile("missing.txt");
    }
    catch (const exception& e) {
        cout<<"file error: "<<e.what()<<endl;
    }
    ofstream out("test.txt");
    out<<"hello missin file";
    out.close();

    try {
        string text= readFromFile("test.txt");
        cout<<"file content: "<<text<<endl;
    }
    catch (const exception& e) {
        cout<<"file error: "<<e.what()<<endl;
    }
    return 0;
}