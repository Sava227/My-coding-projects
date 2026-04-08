#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

template <typename Container, typename Compare>

void sort_container(Container& container, Compare comp) {
    sort(container.begin(), container.end(), comp);
}

struct compare_by_age {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

int main() {
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    sort_container(people, [](const Person& a, const Person& b) {
        return a.name < b.name;
    });

    for (const auto& p : people) {
        cout<<p.name<<" "<<p.age<<endl;
    }
    sort_container(people, compare_by_age());
    for (const auto& p : people) {
        cout<<p.name<< " "<< p.age<<endl;
    }

    return 0;
}