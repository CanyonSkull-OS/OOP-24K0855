#include <iostream>
#include <string>
using namespace std;

class InventoryManager;

class Car {
    string model;
    double price;

public:
    Car(string m = "", double p = 0.0) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(Car& c1, Car& c2);
};

class InventoryManager {
public:
    void updatePrice(Car& c, double newPrice) {
        c.price = newPrice;
    }

    void displayCar(Car& c) {
        cout << "Model: " << c.model << endl;
        cout << " Price: " << c.price << endl;
    }
};

void comparePrice(Car& c1, Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c2.price > c1.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    InventoryManager manager;

    Car car1("Toyota Supra", 55000.0);
    Car car2("Ford Mustang", 53000.0);

    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car2, 56000.0);

    manager.displayCar(car1);
    manager.displayCar(car2);

    comparePrice(car1, car2);

    return 0;
}
