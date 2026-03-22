#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//check the text if the letter in eng
bool isLetter(char ch) {
    return isalpha(ch);
}

//convert the text to uppercase
int letterToIndex(char ch) {
    return toupper(ch) - 'A';
}

char indexToLetter(int index) {
    return 'A' + index;
}

//assign the number for the letter
int normalizeKey(int key) {
    key %= 26;
    if (key < 0) key += 26; //go backward in alphbt
    return key;
}

//encrypts or decrypts a message
string atbash(string message) {
    string result = "";

    for (char ch : message) {
        if (isLetter(ch)) {
            int index = letterToIndex(ch);
            //Atbash logic: reverse the alphabet (25 - index)
            int newIndex = 25 - index;
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
    cout<<"welcome to atbash enc"<<endl;
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

        if (choice == 1 || choice == 2) {
            cout<<"type in your message "<<endl;
            string message;
            getline(cin, message);

            string result = atbash(message);

            cout<<"original: "<<message<<endl;
            cout<<"eesult: "<<result<<endl;
        } else {
            cout<<"error!"<<endl;
            continue;
        }
    }

    cout<<"see you later :)"<<endl;
    return 0;
}
