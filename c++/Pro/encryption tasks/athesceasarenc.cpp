#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//check the text if the letter in eng
bool isLetter(char ch) {
    return isalpha(ch);
}

//convert the text to uppercase index 0-25
int letterToIndex(char ch) {
    return toupper(ch) - 'A';
}

char indexToLetter(int index) {
    return 'A' + index;
}

//modular inverse for affine decryption
int modInverse(int a) {
    a %= 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) return x;
    }
    return 1;
}

//encrypts or decrypts a message
string affine(string message, int a, int b, bool encrypt) {
    string result = "";
    int inv = modInverse(a);

    for (char ch : message) {
        if (isLetter(ch)) {
            int x = letterToIndex(ch);
            int newIndex;

            if (encrypt) {
                newIndex = (a * x + b) % 26;
            } else {
                newIndex = (inv * (x - b + 26)) % 26;
            }

            char newCh = indexToLetter(newIndex);
            //keep original case
            if (islower(ch)) newCh = tolower(newCh);
            result += newCh;
        } else {
            result += ch; //spaces&punctuation stay the same
        }
    }
    return result;
}

int main() {
    cout<<"welcome to affine enc"<<endl;
    cout<<"only english letters are supported"<<endl;

    while (true) {
        cout<<"menu:"<<endl;
        cout<<"1.encrypt message"<<endl;
        cout<<"2.decrypt message"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"Choose: ";
        int choice;
        cin>>choice;
        cin.ignore(); //clear input

        if(choice == 0) break;

        cout<<"type in your message "<<endl;
        string message;
        getline(cin, message);

        cout<<"enter key2 (multiplier): ";
        int a; cin>>a;
        cout<<"enter key1 (shift): ";
        int b; cin>>b;
        cin.ignore();

        string result;
        if (choice == 1) {
            result = affine(message, a, b, true);
        } else if (choice == 2) {
            result = affine(message, a, b, false);
        } else {
            cout<<"error!"<<endl;
            continue;
        }

        cout<<"original: "<<message<<endl;
        cout<<"eesult: "<<result<<endl;
    }

    cout<<"see you later :)"<<endl;
    return 0;
}
