#include <iostream>
#include <string>
using namespace std;

class Apartment {
    int id;
    string address;
    string* ownerName;

public:
    Apartment(int id, string address,const string &owner) : id(id), address(address) {
        ownerName = new string(owner);
    }

    Apartment(const Apartment &obj) : id(obj.id), address(obj.address) {
        ownerName = obj.ownerName;
    }

    ~Apartment() {
       cout << "Apartment Destroyed" << endl;
    }

    void displayDetails() const {
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << *ownerName << endl;
    }
};

int main() {
    Apartment apt1(101, "Dhoraji", "Ali");
    Apartment apt2(102, "Bahadurabad", "Ayesha");

    apt1.displayDetails();
    apt2.displayDetails();

    Apartment apt1_copy(apt1); 

    apt1.displayDetails();
    apt1_copy.displayDetails();

    apt1.displayDetails();
    apt1_copy.displayDetails();

    return 0;
}