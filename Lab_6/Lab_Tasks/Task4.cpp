#include <iostream>
using namespace std;

class Account{
    protected:
        int accountNumber;
        float balance;

    public:
        Account(int an, float b) : accountNumber(an), balance(b){}

        void display(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingsAccount : public Account{
    protected:
        float interestRate;

    public:
            SavingsAccount(int an, float b, float ir) : Account(an, b),
                interestRate(ir){}

            void display(){
                Account::display();
                cout << "Interest Rate: " << interestRate << endl;
            }
};

class CheckingAccount : public Account{
    protected:
        float overdraftLimit;

    public:
        CheckingAccount(int an, float b, float ol) : Account(an, b),
            overdraftLimit(ol){}

        void display(){
                Account::display();
                cout << "Overdraft Limit: " << overdraftLimit << endl;
            }
};

int main(){
    SavingsAccount sa1(1092309, 12000.00, 1.2);
    CheckingAccount ca1(1092309, 12000.00, 20000.00);

    sa1.display();
    ca1.display();

    return 0;
}