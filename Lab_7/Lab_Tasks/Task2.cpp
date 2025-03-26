#include <iostream>
using namespace std;

class Product {
protected:
    int ID;
    string Name;
    double price;
    int stockQuantity;

public:
    Product(int id, string n, double p, int sq) : ID(id), Name(n), price(p), stockQuantity(sq) {}

    virtual void applyDiscount() {
        price *= 0.8;
    }

    virtual double calculateTotalPrice(int quantity) {
        return quantity * price;
    }

    virtual void displayProductInfo() {
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }

    double getPrice(){
        return price;
    }

    string getName(){
        return Name;
    }

    Product operator+(Product& other) {
        return Product(0, "Bulk Purchase", this->price + other.price, 0);
    }

    void operator<<(Product& product) {
        product.displayProductInfo();
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string n, double p, int sq, int wp, string b) 
        : Product(id, n, p, sq), warrantyPeriod(wp), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " years" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
    int size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string n, double p, int sq, int s, string c, string fm) 
        : Product(id, n, p, sq), size(s), color(c), fabricMaterial(fm) {}

    void applyDiscount() override {
        if (fabricMaterial == "Silk") {
            price *= 0.8;
        } else if (fabricMaterial == "Cotton") {
            price *= 0.7;
        } else {
            price *= 0.9;
        }
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string n, double p, int sq, string expDate, int cal) 
        : Product(id, n, p, sq), expirationDate(expDate), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        double total = quantity * price;
        if (quantity > 10) {
            total *= 0.9;
        }
        return total;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Calories: " << calories << " kcal" << endl;
    }
};

class Book : public Product {
    string author;
    string genre;

public:
    Book(int id, string n, double p, int sq, string a, string g) 
        : Product(id, n, p, sq), author(a), genre(g) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics laptop(101, "Laptop", 1200.99, 10, 2, "Dell");
    Clothing tshirt(102, "T-Shirt", 20.5, 50, 42, "Blue", "Cotton");
    FoodItem pizza(103, "Pizza", 15.99, 30, "2025-06-15", 300);
    Book novel(104, "The Great Gatsby", 10.99, 100, "F. Scott Fitzgerald", "Fiction");

    laptop.displayProductInfo();

    tshirt.applyDiscount();
    tshirt.displayProductInfo();

    cout << "Total price for 12 pizzas: $" << pizza.calculateTotalPrice(12) << endl;
    pizza.displayProductInfo();

    Product bundle = laptop + tshirt;
    cout << "Bundle Total Price: $" << bundle.getPrice() << endl;

    cout << "Laptop Details: ";
    laptop << laptop;

    cout << "T-Shirt Details: ";
    tshirt << tshirt;

    return 0;
}
