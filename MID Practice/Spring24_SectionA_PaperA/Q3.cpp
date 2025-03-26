#include <iostream>
using namespace std;

class Reward {
private:
    bool complimentaryDish;
    bool freeDrink;
    int rewardPoints;

public:
    Reward() : complimentaryDish(false), freeDrink(false), rewardPoints(0) {}

    void checkEligibility(int numDishes, int numDrinks, int age, string orderType) {
        if (orderType == "Dine-in") {
            if (numDishes > 2 && numDrinks >= 1) {
                complimentaryDish = true;
            }
            if (age < 5 || age > 70) {
                freeDrink = true;
            }
        }
    }

    void assignRewardPoints(double orderAmount) {
        rewardPoints += (int)(orderAmount / 10);
    }

    void displayRewards() const {
        cout << "Rewards:\n";
        if (complimentaryDish) cout << "- Complimentary Dish granted!\n";
        if (freeDrink) cout << "- Free Drink granted!\n";
        cout << "- Reward Points Earned: " << rewardPoints << endl;
    }
};

class Order {
private:
    static int orderCounter;
    int orderID;
    double amount;
    string orderType;
    int numDishes;
    int numDrinks;
    Reward reward;

public:
    Order() : orderID(0), amount(0), numDishes(0), numDrinks(0) {}

    void placeOrder(double amt, string type, int dishes, int drinks, int customerAge) {
        orderID = ++orderCounter;
        amount = amt;
        orderType = type;
        numDishes = dishes;
        numDrinks = drinks;
        reward.checkEligibility(numDishes, numDrinks, customerAge, orderType);
        reward.assignRewardPoints(amount);
    }

    void displayOrder() const {
        if (orderID == 0) return;  // Skip empty orders
        cout << "Order ID: " << orderID << "\nType: " << orderType
             << "\nTotal Amount: $" << amount
             << "\nDishes: " << numDishes << ", Drinks: " << numDrinks << endl;
        reward.displayRewards();
    }
};

int Order::orderCounter = 0;

class Customer {
private:
    string name;
    int age;
    int numOrders;
    Order* orders;  // Dynamic array of orders

public:
    Customer(string _name, int _age, int maxOrders)
        : name(_name), age(_age), numOrders(0) {
        orders = new Order[maxOrders];  // Allocate memory for storing orders
    }

    ~Customer() {
        delete[] orders;  // Free allocated memory
    }

    void placeOrder(double amount, string type, int dishes, int drinks) {
        if (numOrders < 10) {  // Limit to 10 orders for simplicity
            orders[numOrders].placeOrder(amount, type, dishes, drinks, age);
            numOrders++;
        } else {
            cout << "Maximum order limit reached!\n";
        }
    }

    void displayCustomerInfo() const {
        cout << "Customer: " << name << "\nAge: " << age << "\nOrder History:\n";
        for (int i = 0; i < numOrders; i++) {
            orders[i].displayOrder();
            cout << "---------------------------\n";
        }
    }
};

int main() {
    Customer cust1("Ali Khan", 72, 10);
    cust1.placeOrder(50, "Dine-in", 3, 1);
    cust1.placeOrder(30, "Takeout", 2, 0);
    cust1.displayCustomerInfo();

    return 0;
}
