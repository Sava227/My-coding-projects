#include <iostream>
#include <list>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    string group;
    double average_grade;

public:
    Student(string name, int age, string group, double averageGrade) {
        this->name = name;
        this->age = age;
        this->group = group;
        this->average_grade = averageGrade;
    }

    string getName() const {
        return name;
    }

    void print() const {
        cout<<"Name: "<<name<<", Age: "<<age<<", Group: "<<group<<", Average grade: "<<average_grade<<endl;
    }
};

class StudentSystem {
private:
    list<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void findStudent(const string& name) const {
        bool found = false;
        for (const auto& student : students) {
            if (student.getName() == name) {
                student.print();
                found = true;
            }
        }
        if (!found) {
            cout<<"Student not found"<<endl;
        }
    }

    void removeStudent(const string& name) {
        for (auto it = students.begin(); it != students.end(); ) {
            if (it->getName() == name) {
                it = students.erase(it);
            } else {
                ++it;
            }
        }
    }

    void printAll() const {
        for (const auto& student : students) {
            student.print();
        }
    }
};

int main() {
    StudentSystem system;

    system.addStudent(Student("blu blu", 20, "CS101", 4.5));
    system.addStudent(Student("bla bla", 19, "CS102", 4.2));

    cout<<"all students:"<<endl;
    system.printAll();

    cout<<"search for blu blu:"<<endl;
    system.findStudent("blu blu");

    cout<<"removing 'blu blu'"<<endl;
    system.removeStudent("blu blu");

    cout<<"all students after removal:"<<endl;
    system.printAll();

    return 0;
}