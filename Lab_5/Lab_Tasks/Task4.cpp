#include <iostream>
using namespace std;

class Alarmsystem{
    string securityLevel;
    string manufacturingYear;
    int yearsOfWarranty;

public:
    Alarmsystem(string secLevel, string Year, int war) :
        securityLevel(secLevel), manufacturingYear(Year),
        yearsOfWarranty(war){}

    ~Alarmsystem(){
        cout << "Alarm Destroyed" << endl;
    }

    void displayDetails(){
        cout << "Level: " << securityLevel << endl;
        cout << "Year of Manufacturing: " << manufacturingYear << endl;
        cout << "Warranty Years: " << yearsOfWarranty << endl;
    }

};

class SmartHome{
    Alarmsystem alarm;

public:
    SmartHome(Alarmsystem& alarm) : alarm(alarm){} 

    ~SmartHome(){
        cout << "SmartHome Destroyed" << endl;
    }

    void displayDetails(){
        cout << "Alarm Details" << endl;
        alarm.displayDetails();
    }
};

int main(){
    Alarmsystem alarm("High", "2021", 3);

    SmartHome smartHome(alarm); 

    smartHome.displayDetails();

    return 0;
}