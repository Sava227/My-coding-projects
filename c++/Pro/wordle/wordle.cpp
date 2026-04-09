#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>
using namespace std;

class word_list {
private:
    vector<string> words;

public:
    bool load_file(const string& filename) {
        ifstream file(filename);
        if (!file) return false;

        string word;
        while (file >> word) {
            if (word.length() == 5) {
                words.push_back(word);
            }
        }
        return true;
    }

    string get_word() {
        if (words.empty()) return "";
        int index = rand() % words.size();
        return words[index];
    }
};

class game {
private:
    string secret_word;
    int max_attempts;

public:
    game(const string& word, int attempts = 10)
        : secret_word(word), max_attempts(attempts) {}

    string colored_feedback(const string& guess) {
        string result = "";

        for (int i = 0; i < 5; i++) {
            if (guess[i] == secret_word[i]) {
                result +="\033[1;32m";  //green color, correct letter, correct positon
                result += guess[i];
            }
            else if (secret_word.find(guess[i]) != string::npos) {
                result += "\033[1;33m"; //yellow color, letter correct, position not
                result += guess[i];
            }
            else {
                result += "\033[1;37m"; //gray, letter not in word
                result += guess[i];
            }
            result += "\033[0m"; //reset
            result += " ";
        }
        return result;
    }

    void play() {
        cout<<"Welcome to Wordle!"<<endl;
        cout<<"Guess 5 letter word!"<<endl;

        for (int attempt = 1; attempt <= max_attempts; attempt++) {
           string guess;
           cout<<"\n Attempt "<<attempt<<" / "<<max_attempts<<": ";
           cin>>guess;

            if (guess.length() != 5) {
                cout<<"Please enter a 5 letter word."<<endl;
                attempt--;
                continue;
            }

            cout<<"Result: "<<colored_feedback(guess)<<endl;

            if (guess == secret_word) {
                cout<<"You guessed it!"<<endl;
                return;
            }
        }
        cout<<"Game over! The word was: "<<secret_word<<endl;
    }
};

int main() {
    srand(time(0));
    word_list wordlist;

    if (!wordlist.load_file("words.txt")) {
      cout<<"ERROR! Can't load words!"<<endl;
        return 1;
    }

    string secret = wordlist.get_word();
    game g(secret);

    g.play();
    return 0;
}