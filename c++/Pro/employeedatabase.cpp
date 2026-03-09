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
    bool is_active = true;

public:
    employee() = default;           //default contruct
    employee(string name, int age, int salary, string pos)
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
    void setSalary  (int s)                   {if (s >= 0) salary = s;}
    void setPosition(const string& pos)       {position = pos;}
    void setActive  (bool active)             {is_active = active;}

    //allign the output :)
    string toString() const {
        if (!is_active) return "";

        return "  " + full_name + "\n" +
               "    Age    : " + to_string(age)     + "\n"
               "    Salary   : " + to_string(salary)  + " rub.\n"
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

        //add the new employee
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
        //is_activ = true
        staff.emplace_back(name, age, salary, position);
        cout<<"The employee has been added successfully."<<endl;
    }

    void delete_employee()
    {
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
        for (auto& emp : staff)
        {
            if (emp.getName() == name && emp.isWorking()) {
                emp.setActive(false);
                cout<<"Employee: "<<name<<"is marked and fired"<<endl;
                found = true;
                break;
            }
        }

        if (!found)