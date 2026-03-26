#include <iostream>
#include <string>

using namespace std;

template <class T>
class array_sorter {
private:
    T* arr;
    int size;

public:
    array_sorter(T data[], int s) {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = data[i];
        }
    }

    ~array_sorter() {
        delete[] arr;
    }

    void bubble_sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout<<arr[i]<<" "<<endl;
        }
        cout<<endl;
    }
};

int main() {
    int intData[] = {5, 2, 9, 1, 5, 6};
    array_sorter<int> int_obj(intData, 6);
    
    cout<<"Numbers before dorting: "<<endl;
    int_obj.display();
    int_obj.bubble_sort();
    cout<<"After: "<<endl;
    int_obj.display();

    double doubleData[] = {3.14, 1.59, 2.65, 0.58};
    array_sorter<double> double_obj(doubleData, 4);
    
    cout<<"Fravtions: "<<endl;
    double_obj.display();
    double_obj.bubble_sort();
    cout<<"After: "<<endl;
    double_obj.display();

    return 0;
}
