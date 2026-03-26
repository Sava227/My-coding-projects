#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<limits>
using namespace std;

class employee
{
private:
    string full_name;
    int age = 0;
    int salary = 0;
    string position;
    bool is_active = true;      //indicate if someone is currentky working

public:
    employee() = default;           //default contruct
    employee(string name, int age, int salary, string pos)      //construct of class employee, hwich creates whe object of employee and fills the data in
    :     full_name(move(name)),
          age(age),
          salary(salary),
          position(move(pos)),
          is_active(true) {}

    //get
    string getName()        const{return full_name;}
    string getamPosition()  const{return position;}
    int getSalary()         const{return salary;}
    int getAge()            const{return age;}
    bool isWorking()        const{return is_active;}

    //set
    void setName    (const string& name)      {full_name = name;}
    void setAge     (int a)                   {if (a > 0) age = a;}
    void setSalary  (int s)                   {if (s >= 0) salary = s;}     //salary cant be negetive
    void setPosition(const string& pos)       {position = pos;}
    void setActive  (bool active)             {is_active = active;}

    //allign the output :) + convert to string
    string toString() const {
        if (!is_active) return "";          //if not active, then fired + wond show up

        return "  " + full_name + "\n" +        //create 1 string of info about the employee
               "    Age    : " + to_string(age)     + "\n"
               "    Salary   : " + to_string(salary)  + " usd.\n"
               "    Position  : " + position + "\n";
    }
};

class hrsystem
{
private:
    vector<employee> staff;

public:
    void add_employee()
    {
        string name, position;
        int age = 0, salary = 0;

        //add the new employee comfortable menu
        cout<<"---------------------Add the new employee---------------------"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"-------------------Name, Surname, Lastname--------------------"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    //clear thr imput *_*
        getline(cin, name);
        cout<<"----------------------------Age-------------------------------"<<endl;
        cin>>age;
        cout<<"--------------------------Salary USD $------------------------"<<endl;
        cin>>salary;
        cout<<"--------------------------Position----------------------------"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    //clear thr imput *_*
        getline(cin, position);
        //add empl. to vector
        staff.emplace_back(name, age, salary, position);
        cout<<"The employee has been added successfully."<<endl;
    }

    void delete_employee()  //fire employee
    {
        //check if there r employees
        if (staff.empty()) {
            cout<<"The employee is not in eployed yet"<<endl;
            return;
        }
        string name;
        cout<<"Firing the employee"<<endl;
        cout<<"Please enter the name of the employee: "<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    //clear thr imput *_*
        getline(cin, name);

        bool found = false;
        //search for empl
        for (auto& emp : staff)
        {
            if (emp.getName() == name && emp.isWorking()) {
                emp.setActive(false);
                cout<<"Employee: "<<name<<"is marked and fired"<<endl;
                found = true;
                break;
            }
        }
        //empl not found
        if (!found)
        {
            cout<<"The employee is not in eployed yet"<<endl;
        }
    }

    //show all active empl
    void showactive() const
    {
        if (staff.empty())
        {
            cout<<"The employee is not in eployed yet"<<endl;
            return;
        }

        cout<<"The list of active employees: "<<endl;

        bool anyone = false;
        for (const auto& emp : staff) {
            if (emp.isWorking()) {
                cout << emp.toString() << "\n";
                anyone = true;
            }
        }

        if (!anyone)
        {
            cout<<"There are no active employees"<<endl;
        }
    }

        //menu :p
    bool menu() {
        cout<<"HR System console"<<endl;
        cout<<"1. Show all employees"<<endl;
        cout<<"2. Fire the employee"<<endl;
        cout<<"3. Hire the employee"<<endl;
        cout<<"0. Quit"<<endl;
        int choice;
        cin >> choice;

        switch (choice) {               //shorter case to make shorter code :)
        case 1: showactive();      return false;
        case 2: delete_employee();     return false;
        case 3: add_employee();        return false;
        case 0: return true;
        default:
            cout<<"ERROR! Please try again"<<endl;
            return false;
        }
    }
};

int main()
{
    hrsystem hr;        //create the obj
    cout<<"Welcome to the HR System"<<endl;
    while (!hr.menu()) {    //loop unti i choose to quit
    }
    cout<<"See you later! :)"<<endl;
    return 0;
}
