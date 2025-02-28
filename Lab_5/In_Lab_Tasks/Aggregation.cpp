#include <iostream>
using namespace std;

class Employee{
        string name;
        int employeeID;

    public:
        Employee(string name, int employeeID) : name(name), employeeID(employeeID){}

        void display(){
            cout << "Employee name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;

        }
};

class Department{
    string deptname;
    Employee* e[10];
    int employeeCount = 0;
    Employee &e4;

    public:
        Department(string deptname, Employee &e3) : deptname(deptname), e4(e3){}

        void addEmployee(Employee* e1){
            e[employeeCount++] = e1;
        }

        void display(){
            e4.display();
            cout << "Dept Name: " << deptname << endl;
            for (int i = 0; i < employeeCount; i++)
            {
                e[i]->display();
            }
        }

};

int main(){
    
    Employee talha("Talha Shahid", 1040), abc("Another Employee", 102), head("Sir Aashir", 0605);

    Department d1("Computer Science", head);

    d1.addEmployee(&talha);
    d1.addEmployee(&abc);

    d1.display();

    cout << "Independant Entity" << endl;
    talha.display();

    return 0;

}