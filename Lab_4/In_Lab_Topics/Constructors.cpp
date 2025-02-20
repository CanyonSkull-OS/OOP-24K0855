#include <iostream>
using namespace std;


class BankAccount{
    string name;
    double balance;
    bool isActive = false;

    public:
        BankAccount(){
            name = "Unknown";
            balance = 0.0;
        }

        BankAccount(string n, double b){
            name = n;
            balance = b;
        }

        void deposit(double amount){
            if (amount >= 0){
                balance += amount;
                cout << "Balance updated" << endl;
            }
            else{
                cout << "Kanglay insan" << endl;
            }
        }

        void withdraw(double amount){
            if (amount <= balance && amount >= 0){
                balance -= amount;
                cout << "Amount Withdrawn";
            }
            else{
                cout << "Not enough money, loser" << endl;
            }
        }

        void display(){
            cout << "-----------------------" << endl;
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
            cout << "-----------------------" << endl;
        }
};


int main(){

    BankAccount Talha;
    Talha.deposit(5000);
    Talha.deposit(2000);
    Talha.withdraw(1499.3);
    Talha.display();

    BankAccount t1("Omer", 3000.0);

    t1.display();

    return 0;
}