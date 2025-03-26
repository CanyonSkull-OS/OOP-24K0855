#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string c, string addr = "") 
        : name(n), age(a), contactNumber(c), address(addr) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        if (address != "") {
            cout << "Address: " << address << endl;
        }
    }

    virtual void updateInfo(string newContact) {
        contactNumber = newContact;
    }

    void operator<<(Person& person) {
        person.displayInfo();
    }
};

class Patient : public Person {
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string c, int id, string mh, string da, string addr = "") 
        : Person(n, a, c, addr), patientID(id), medicalHistory(mh), doctorAssigned(da) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string c, string spec, double fee, string plist, string addr = "") 
        : Person(n, a, c, addr), specialization(spec), consultationFee(fee), patientsList(plist) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Patients List: " << patientsList << endl;
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string c, string ward, string shift, string addr = "") 
        : Person(n, a, c, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;

public:
    Administrator(string n, int a, string c, string dept, double sal, string addr = "") 
        : Person(n, a, c, addr), department(dept), salary(sal) {}

    void updateInfo(double newSalary) {
        salary = newSalary;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Patient patient1("John Doe", 30, "123456789", 101, "Diabetes", "Dr. Smith");
    Doctor doctor1("Dr. Smith", 45, "987654321", "Cardiology", 200.0, "John Doe, Jane Doe");
    Nurse nurse1("Alice Brown", 35, "555667788", "ICU", "Night");
    Administrator admin1("Robert White", 50, "444333222", "HR", 60000.0);

    patient1.displayInfo();
    cout << endl;
    doctor1.displayInfo();
    cout << endl;
    nurse1.displayInfo();
    cout << endl;
    admin1.displayInfo();

    patient1 << doctor1;

    return 0;
}
