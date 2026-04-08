#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;        //all datatypess
    Node* next;    //pointer for the next tie

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

//list
template <typename T>
class LinkedList {
private:
    Node<T>* head;   //beginning of the list

public:
    LinkedList() {
        head = nullptr;
    }

    //add to the beginning of the list
    void insert(T value) {
        Node<T>* new_Node = new Node<T>(value);
        new_Node->next = head;
        head = new_Node;
    }

    //remove element
    void remove(T value) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == value) {
                if (prev == nullptr) {
                    //remove the 1st element
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    //find element
    bool find(T value) {
        Node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    //print the list
    void print() {
        Node<T>* temp = head;

        while (temp != nullptr) {
            cout<<temp->data<<" -> "<<endl;
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //destructor to free storage
    ~LinkedList() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.print();

    list.remove(20);
    list.print();

    cout<<"Find 10: "<<list.find(10)<<endl;
    cout<<"Find 50: "<< list.find(50)<<endl;

    return 0;
}