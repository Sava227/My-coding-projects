#include<iostream>
#include<string>
#include<cstudio>
using namespace std;

class Ascii{
public:
    void translate(const string& s) {
        for (size_t i = 0; i < s.size(); ++i) {
            if (i) printf(" ");
            printf("%d", (unsigned char)s[i]);
        }
        printf("\n");
        }
};

int main() {
    Ascii a;
    string s;
    getline(cin, s);

    a.translate(s);
    return 0;
}