#include <iostream>
#include <cstring>  
using namespace std;

class Product {
    int id;
    char name[50];
    int quantity;

public:
    Product() {}

    Product(int i, char* n, int q) : id(i), quantity(q) {
        strncpy(name, n, 49);
        name[49] = '\0';
    }

    int getID() {
        return id;
    }

    char* getName() {
        return name;
    }

    void display() {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Quantity in Stock: " << quantity << endl;
    }
};

class Warehouse {
    Product products[100];
    int size;

public:
    Warehouse() : size(0) {}

    void addProduct(Product p) {
        if (size < 100) {
            products[size] = p;
            size++;
        }
    }

    void sortProducts() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(products[j].getName(), products[j + 1].getName()) > 0) {
                    Product temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
    }

    void searchProduct(int id) {
        for (int i = 0; i < size; i++) {
            if (products[i].getID() == id) {
                products[i].display();
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            products[i].display();
        }
    }
};

int main() {
    Warehouse warehouse;

    Product p1(101, "Laptop", 15);
    Product p2(102, "Chair", 30);
    Product p3(103, "Table", 20);
    Product p4(104, "Phone", 25);
    Product p5(105, "Mouse", 50);

    warehouse.addProduct(p1);
    warehouse.addProduct(p2);
    warehouse.addProduct(p3);
    warehouse.addProduct(p4);
    warehouse.addProduct(p5);

    warehouse.sortProducts();
    warehouse.display();

    int searchID;
    cout << "Enter product ID to search: ";
    cin >> searchID;
    warehouse.searchProduct(searchID);

    return 0;
}
