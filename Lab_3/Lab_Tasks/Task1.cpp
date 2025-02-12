#include <iostream>
using namespace std;

class Wallet{
    int count = 0;
    string ownerName;
    double totalBalance = 0;
    double transactionHistory[100];
    
    public:
        void addMoney(double money){
            if (count < 100){
                totalBalance += money;
                transactionHistory[count] = totalBalance;
                count++;
                cout << "Balance Updated" << endl;
            }
            else{
                cout << "Transaction History Full" << endl;
                for (int i = 0; i < count; i++)
                {
                    transactionHistory[count] = 0;
                }
                count = 0;
                cout << "Transaction History Formatted" << endl;
            }
        }
        
        void spendMoney(double money){
            if (count < 100){
                totalBalance -= money;
                transactionHistory[count] = totalBalance;
                count++;
                cout << "Balance Updated" << endl;
            }
            else{
                cout << "Transaction History Full" << endl;
                for (int i = 0; i < count; i++)
                {
                    transactionHistory[count] = 0;
                }
                count = 0;
                cout << "Transaction History Formatted" << endl;
            }
        }

        void displayHistory(){
            cout << "\t\t Transaction History \t\t" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << transactionHistory[i] << endl;
            }
        }

        void checkBalance(){
            if (totalBalance < 500){
                cout << "Your balance: " << totalBalance << endl;
                cout << "Get a job" << endl;
            }
            else{
                cout << "Your balance: " << totalBalance << endl;
            }
        }
};


int main(){
    Wallet wallet1;
    double money;

    cout << "Enter Money to add: ";
    cin >> money;
    wallet1.addMoney(money);
    
    cout << "Enter Money to spend: ";
    cin >> money;
    wallet1.spendMoney(money);

    wallet1.checkBalance();

    wallet1.displayHistory();


    return 0;
}