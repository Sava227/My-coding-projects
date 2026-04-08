#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Field {
protected:
    char field[3][3];
    int rows = 3;
    int cols = 3;

public:
    Field() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                field[i][j] = '+';
            }
        }
    }

    void print_field() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " <<field[i][j] << " ";
                if (j < 2) cout<<"|";
            }
            cout << endl;
            if (i < 2) cout<<"---+---+---"<<endl;
        }
        cout << endl;
    }

    bool has_empty() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[i][j] == '+') return true;
            }
        }
        return false;
    }

    bool place(int pos, char ch) {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if (pos < 1 || pos > 9 || field[row][col] != '+') {
            return false;
        }

        field[row][col] = ch;
        return true;
    }

    bool check_win(char player) {
        for (int i = 0; i < 3; i++) {
            if (field[i][0] == player && field[i][1] == player && field[i][2] == player) return true;
            if (field[0][i] == player && field[1][i] == player && field[2][i] == player) return true;
        }

        if (field[0][0] == player && field[1][1] == player && field[2][2] == player) return true;
        if (field[0][2] == player && field[1][1] == player && field[2][0] == player) return true;

        return false;
    }
};

class Game : public Field {
private:
    bool running = true;
    bool player_turn = true;

public:
    void start_game() {
        srand(time(0));
        cout<<"Tic-Tac-Toe"<<endl;
        cout<<"You are playing as X"<<endl;
        cout<<"Computer is playing as O"<<endl;

        while (running) {
            print_field();

            if (player_turn) {
                int input;
                cout<<"Your move (X). Enter a number 1-9: "<<endl;
                cin >> input;

                if (!place(input, 'X')) {
                    cout<<"Invalid move! Cell is occupied or number is incorrect."<<endl;
                    continue;
                }
            } 
            else {
                cout<<"Computer move (O)..."<<endl;
                int input;
                do {
                    input = rand() % 9 + 1;
                } while (!place(input, 'O'));
            }

            bool x_win = check_win('X');
            bool o_win = check_win('O');

            if (x_win || o_win || !has_empty()) {
                print_field();
                if (x_win) {
                    cout<<"Congratulations! X wins!"<<endl;
                } 
                else if (o_win) {
                    cout<<"Computer wins! O wins."<<endl;
                } 
                else {
                    cout<<"Draw! Board is full."<<endl;
                }
                running = false;
            }

            player_turn = !player_turn;
        }
    }
};

int main() {
    Game ticTacToe;
    ticTacToe.start_game();
    return 0;
}