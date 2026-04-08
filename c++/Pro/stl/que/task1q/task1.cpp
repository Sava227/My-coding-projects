#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Order {
private:
    int id;
    string customer;
    string product;
    int quantity;

public:
    Order(int i, string c, string p, int q) {
        id = i;
        customer = c;
        product = p;
        quantity = q;
    }

    int get_id() const {
        return id;
    }

    void print() const {
        cout<<"Order ID: "<<id<<endl;
        cout<<"Customer: "<<customer<<endl;
        cout<<"Product: "<<product<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
};

//removing the order by id
void remove_order(queue<Order>& orders, int id) {
    queue<Order> temp;

    while (!orders.empty()) {
        if (orders.front().get_id() != id) {
            temp.push(orders.front());
        }
        orders.pop();
    }

    //retunr
    while (!temp.empty()) {
        orders.push(temp.front());
        temp.pop();
    }
}

//copy
void print_queue(queue<Order> orders) {
    while (!orders.empty()) {
        orders.front().print();
        orders.pop();
    }
}

int main() {
    queue<Order> orders;

    //orders
    orders.push(Order(1, "Michael", "laptop", 1));
    orders.push(Order(2, "Bob", "phone", 2));
    orders.push(Order(3, "Donald", "tablet", 1));

    cout<<"before removing:"<<endl;
    print_queue(orders);

    //removing
    cout<<"removing order with id  2"<<endl;
    remove_order(orders, 2);

    cout<<"after removing:"<<endl;
    print_queue(orders);

    return 0;
}