#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <chrono>
using namespace std;

class KeyboardRace {
private:
    chrono::steady_clock::time_point start_time;     //time when the user starts typing
    chrono::steady_clock::time_point finish_time;    //time when the user finishes typing
    double result_time;     //total time taken in seconds
    string target_phrase;   //phrase the user must type
    string typed_text;      //text entered by the user

public:
        //clear the input
    void clearInputBuffer() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //constructor initialize result_time to 0
    KeyboardRace() : result_time(0.0) {}

    //3 sec countdown
    void countdown() {
        cout<<"Game starts in..."<<endl;
        for (int i = 3; i >= 1; --i) {
            cout<<i<<" "<<endl;     //display cutdown number
            cout.flush();          //force cutdown to appearimidiately
            clock_t end = clock() + CLOCKS_PER_SEC;
        }
        cout<<"GO!"<<endl;      //start typing :D
    }

    void show_phrase() {        //phrase to type
        cout<<"Type exactly this phrase: "<<endl;
        cout<<target_phrase<<endl;
    }

    //read the line
    void read_input() {
        cout<<"Start typing now: > "<<endl;
        getline(cin, typed_text);       // reads line INCLUDING spaces
    }

    //calculting the time user wrore the phrase in
    double calculate_time() {
        chrono::duration<double> elapsed = finish_time - start_time;
        return elapsed.count();
    }

    //select the random phrase in phrases.txt
    string pick_random_phrase() {
        ifstream file("phrases.txt");   //open the file :>
        vector<string> phrases;        //store the vetor of them

        //if failed to open use this phrs
        if (!file.is_open()) {
            cout<<"Warning: phrases.txt not found. Using default phrase."<<endl;
            return "The quick brown fox jumps over the lazy dog";
        }

        //read the line & ingore the line containing whitespaces
        string line;
        while (getline(file, line)) {
            if (!line.empty() && line.find_first_not_of(" \t") != string::npos) {
                phrases.push_back(line);    //add valdi phrs to lst
            }
        }
        file.close();       //close the file aft reading it

        if (phrases.empty()) {      //if phrases were not found return the msg
            return "Please add some phrases to phrases.txt";
        }

        //pick random phrs in vector
        int index = rand() % phrases.size();
        return phrases[index];
    }

    //main func tht runs the game
    void play()
    {
        srand(static_cast<unsigned>(time(nullptr)));
        cout << "        KEYBOARD RACE        "<<endl;
        target_phrase = pick_random_phrase();   //pick rnd phrs
        countdown();                        //run cutdown
        show_phrase();          //show it to usr
        start_time = chrono::steady_clock::now();   //start the timer
        read_input();
        finish_time = chrono::steady_clock::now();  //stop timer
        result_time = calculate_time(); //calculate it

        //check if user typed the phrase correctly
        cout<<"Time: "<<fixed<<setprecision(3)<<result_time<<" seconds"<<endl;
        if (typed_text == target_phrase) {
            cout<<"Perfect! 100% accuracy!"<<endl;
            cout<<"Your typing speed was excellent!"<<endl;
        } else {//shpw mistakes
            cout<<"Mistake found."<<endl;
            cout<<"You typed : "<<typed_text<<endl;
            cout<<"Needed    : "<< target_phrase <<endl;
            cout<<"Try again to get a clean run!"<<endl;
        }
    }

    //getter fr time res & trg phrase
    double getTime() const { return result_time; }
    string getPhrase() const { return target_phrase; }
};

int main() {

    cout << "      WELCOME TO KEYBOARD RACE!        "<<endl;
    KeyboardRace game;//game obj
    char again = 'y';

    do {
        game.play();
        cout<<"Play again? (y/n): "<<endl;
        cin>>again;
        game.clearInputBuffer();

    } while (again == 'y' || again == 'Y');

    cout<<"Thanks for playing! Goodbye!"<<endl;
    return 0;
}