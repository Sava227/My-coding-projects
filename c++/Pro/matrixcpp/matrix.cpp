#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
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
                data = new int*[rows];               //space for rows
                for (int i = 0; i < rows; i++) {    //space for numbers in each row
                    data[i] = new int[columns]();  //fill with 0s
                }
            }
        }

    matrix(int number, int r, int c) : matrix(r, c) {           //number - тем чем заполняем мвтрицу, r - строки, c - столбцы, number - аргумент при создании обьекта
        fill_with(number);
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
                    data[i][j] = rand() % 19 - 9; //random -9 to 9
                }
            }
        }

    void fill_with(int number) {    //fill with the same number
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    data[i][j] = number;
                }
            }
        }

    void print(string name = "Matrix") const {    //show the matrix nicely
            cout << name << ":" << endl;
            if (rows == 0 || columns == 0) {
                cout<<"empty"<<endl;
                return;
            }
            for (int i = 0; i < rows; i++) {   //loop to print numbers
                for (int j = 0; j < columns; j++) {
                    cout<<data[i][j]<<" ";
                }
                cout << endl;
            }
        }

    matrix transpose() const {
        matrix result(columns, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    matrix sum(const matrix& b) const {
        if (rows != b.rows || columns != b.columns) {
            cout<<"Error! Sizes must match!"<<endl;
            return matrix();
        }
        matrix res(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                res.data[i][j] = data[i][j] + b.data[i][j];
            }
        }
        return res;
    }

    matrix diff(const matrix& b) const {
        if (rows != b.rows || columns != b.columns) {
            return matrix();
        }
        matrix res(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                res.data[i][j] = data[i][j] - b.data[i][j];
            }
        }
        return res;
    }

//convert to vector
        matrix to_vector() const {
        matrix v(1, rows * columns);
        int counter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                v.data[0][counter++] = data[i][j];
            }
        }
        return v;
    }

    int self_sum() const {
        int s = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                s += data[i][j];
            }
        }
        return s;
    }

    //find identical elements
    matrix find_common(const matrix& b) const {
        if (rows != b.rows || columns != b.columns) return matrix();
        matrix c(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                c.data[i][j] = (data[i][j] == b.data[i][j]) ? 1 : 0;
            }
        }
        return c;
    }

    //multiplication
    matrix multiply(const matrix& b) const {
        if (columns != b.rows) {
            cout<<"Error: cannot multiply!"<<endl;
            return matrix();
        }
        matrix c(rows, b.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < b.columns; j++) {
                c.data[i][j] = 0;
                for (int k = 0; k < columns; k++) {
                    c.data[i][j] += data[i][k] * b.data[k][j];
                }
            }
        }
        return c;
    }
};

int main() {
    srand(time(0));

    matrix a(3, 3);
    a.random_fill();
    a.print("matrix a");

    matrix b(3, 3);
    b.random_fill();
    b.print("matrix b");

    matrix c = a.sum(b);
    c.print("a + b");

    matrix d = a.diff(b);
    d.print("a - b");

    matrix t = a.transpose();
    t.print("transpose of a");

    matrix product = a.multiply(b);
    product.print("a * b");

    matrix v = a.to_vector();
    v.print("a as vector");

    int total = a.self_sum();
    cout<<"sum of elements in a: "<<total<<endl;

    matrix common = a.find_common(b);
    common.print("common elements (1 = equal)");

    matrix filled(5, 2, 4);
    filled.print("filled with 5");

    return 0;
}