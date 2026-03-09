#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TV_Channel {
public:
    virtual string getFilm() const = 0;
    virtual ~TV_Channel() = default;
};

class ActionChannel : public TV_Channel {
    vector<string> films = {
        "The Shawshank Redemption",
        "Star warss",
        "The Matrix",
        "The Lord of the Rings: The Return of the King",
    };

public:
    string getFilm() const override {
        return films[rand() % films.size()];
    }
};

class RomanceChannel : public TV_Channel {
    vector<string> films = {
        "Titanic",
        "Casablanca",
        "Romeo&juliet",
    };

public:
    string getFilm() const override {
        return films[rand() % films.size()];
    }
};

void show(const TV_Channel& ch, int times = 1) {
    for (int i = 0; i < times; i++) {
        cout<<"-"<<ch.getFilm()<<"\n";
    }
}

int main() {
    srand(time(nullptr));
    ActionChannel action;
    RomanceChannel romance;
    cout<<"Channel 1 – Blockbusters / Famous Action & Drama:\n";
    show(action, 4);
    cout << "Channel 2 – Romance & Love Stories:\n";
    show(romance, 4);
    return 0;
}