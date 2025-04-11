#include <iostream>
using namespace std;

class Manager;

class Account {
    string accNum;
    double balance;

public:
    Account(string acc = "", double bal = 0.0) : accNum(acc), balance(bal) {}

    void showAccount() const {
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: " << balance << endl;
    }

    friend class Manager;
    friend void transferFunds(Account&, Account&, double);
};

class Manager {
public:
    void deposit(Account& acc, double amount) {
        acc.balance += amount;
        cout << "Deposited " << endl;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrawn" << endl;
        } else {
            cout << "Insufficient Balance" << acc.accNum << endl;
        }
    }

    void displayAccount(const Account& acc) {
        acc.showAccount();
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred" << endl;
    } else {
        cout << "Insufficient Balance" << endl;
    }
}

int main() {
    Manager mgr;

    Account acc1("Omer123", 1000.0);
    Account acc2("Talha456", 500.0);

    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    mgr.deposit(acc1, 300.0);
    mgr.deposit(acc2, 200.0);
    mgr.withdraw(acc1, 150.0);
    transferFunds(acc1, acc2, 400.0);

    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}
