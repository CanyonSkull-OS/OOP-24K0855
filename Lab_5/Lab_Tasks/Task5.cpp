#include <iostream>
using namespace std;


class Doctor{
    string name;
    string specialization;
    int experience;

    public:
        Doctor(){}

        Doctor(string n, string s, int e) : name(n), specialization(s),
            experience(e){}


        void display(){
            cout << "Doctor Name: " << name << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "Experience: " << experience << " years" << endl;
            cout << endl;
            
        }

};

class Hospital{
    Doctor* doctors;
    string name;
    string address;
    int size;


    public:
        Hospital(Doctor* docs, int s, string n, string a) : name(n),
            address(a), size(s){
            doctors = new Doctor[size];
            for (int i = 0; i < size; i++)
            {
                doctors[i] = docs[i];
            }
        }

        ~Hospital(){
            delete doctors;
        }


        void display(){
            cout << "Hospital Name: " << name << endl;
            cout << "Hospital Address: " << address << endl;
            for (int i = 0; i < size; i++)
            {
                doctors[i].display(); 
            }
        }
};

int main(){
    int size;
    cout << "Enter Number of doctors to assign: ";
    cin >> size;
    Doctor* doctors = new Doctor[size];
    for (int i = 0; i < size; i++)
    {
        doctors[i] = Doctor("Omer", "Surgeon", 3); //Default Assignment since question does not specify different attributes
    }
    
    Hospital hospital1(doctors, size, "Agha Khan", "Stadium Road");

    hospital1.display();

    delete doctors;

    return 0;
}