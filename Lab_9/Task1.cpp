#include <iostream>
using namespace std;

class Patient{
    protected:
        string name;
        string id;

    public:
        Patient(string n, string id) : name(n), id(id) {}

        virtual void displayTreatment() = 0;
        virtual double calculateCost() = 0;

};

class InPatient : public Patient{
    int days;
    public:
        InPatient(string n, string id, int d) : Patient(n, id), days(d) {}

        void displayTreatment(){
            cout << "InPatient" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Days: " << days << endl;
        }

        double calculateCost(){
            return days * 1000.0;
        }

};

class OutPatient : public Patient{
    int days;
    public:
        OutPatient(string n, string id, int d) : Patient(n, id), days(d) {}

        void displayTreatment(){
            cout << "OutPatient" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Days: " << days << endl;
        }

        double calculateCost(){
            return days * 1000.0;
        }

};
int main(){
    InPatient patient1("Asad Imran", "6969", 5);
    OutPatient patient2("Abdullah Imran", "1234", 50);
    patient1.displayTreatment();
    cout << "Cost: " << patient1.calculateCost() << endl;
    patient2.displayTreatment();
    cout << "Cost: " << patient2.calculateCost() << endl;
}