#include<iostream>
using namespace std;

class matrix {
    public:
        int rows;         //how many rows
        int columns;     //how many columns
        int **data;     //numbers inside matrix

        matrix(int r = 0, int c = 0) {      //constructor creates empty matrix
            rows = r;
            columns = c;
            data = nullptr;

            if (rows > 0 && columns > 0) {
                data = new int*[rows];      //space for rows
                for (int i = 0; i < rows; i++) {    //space for numbers in each row
                    data[i] = new int[columns]();  //fill with 0s
                }
            }
        }

    ~matrix() { //clean memory when done
            if (data) {
                for (int i = 0; i < rows; i++) {
                    delete[] data[i];
                }
                delete[] data;
            }
        }

    void random_fill() {        //fill the matrix
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    data[i][j] = rand() % 19 - 9;
                }
            }
        }

    void fill_with(int number) {    //fill with the same number
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = number;
                }
            }
        }

    void print(string_name = "Matrix") const {    //show the matrix nicely
            cout<<name<<":"<<endl;
            if (rows == 0 || columns == 0) {
                cout<<"empty"<<endl;
            }
        }
};