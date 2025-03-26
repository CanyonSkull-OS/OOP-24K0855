#include <iostream>
#include <string>
using namespace std;


class Account{
    protected:
    int accNum;
    float balance;
    string creationDate;
    float lastWithdrawalAmount;

    public:
        Account(int accn, float b, string cd, float lwa) : accNum(accn), balance(b),
        creationDate(cd), lastWithdrawalAmount(lwa){}

        void displayDetails(){
            cout << "Account Number: " << accNum << endl;
            cout << "Balance: " << balance << endl;
            cout << "Creation Date: " << creationDate << endl;
            cout << "Last Withdrawal Amount: " << lastWithdrawalAmount << endl;
        }

        ~Account(){
            cout << "Account Destroyed" << endl;
        }

        void deposit(float amount){
            balance += amount;
            cout << amount << " deposited" << endl;
        }

        void withdraw(float amount){
            if(balance > amount){
                balance -= amount;
                cout << amount << " withdrawn" << endl;
            }
            else cout << "Insufficient Funds " << endl;
        }

        int getAccNum(){return accNum;}
        void setAccNum(int accn){accNum = accn;}

        float getBalance(){return balance;}
        void setBalance(float b){balance = b;}

        string getDate(){return creationDate;}
        void setDate(string date){creationDate = date;}

        float getLastWithdrawalAmount(){return lastWithdrawalAmount;}
        void setLastWithdrawalAmount(float amount){lastWithdrawalAmount = amount;}


};

class BasicAccount : public Account{
    public:
    BasicAccount(int accn, float b, string cd, float lwa) : Account(accn, b, cd, lwa){}

    ~BasicAccount(){
        cout << "Basic Account Destroyed" << endl;
    }

};


class SavingsAccount : public Account{
        
    public:
        SavingsAccount(int accn, float b, string cd, float lwa) : Account(accn, b, cd, lwa){}

        void donate(){
            if(lastWithdrawalAmount > 0 && lastWithdrawalAmount < 50){
                if(balance >= 500){
                    int donationamount;
                    cout << "How much? ";
                    cin >> donationamount;
                    balance -= donationamount;
                    cout << donationamount << " Donated" << endl;
                }
            }
        }

        ~SavingsAccount(){
            cout << "Savings account Destroyed" << endl;
        }

        void insurancepremium(){
            balance += balance*0.02;
        }
};

class CheckingsAccount : public Account{
    public:
    CheckingsAccount(int accn, float b, string cd, float lwa) : Account(accn, b, cd, lwa){}

    ~CheckingsAccount(){
        cout << "Checking Account Destroyed" << endl;
    }
};

int main(){
    SavingsAccount s1(124234234, 123210, "20 Nov 2020", 4000);



    return 0;
}