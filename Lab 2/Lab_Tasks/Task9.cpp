#include <iostream>
using namespace std;


struct Product{
    int productID;
    string name;
    int quantity;
    double price;
};


Product* createProdInv(int n){
    Product* prodInv = new Product[n];
    cout << "Inventory created" << endl;
    return prodInv;
}

void inputDetails(Product* products, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details for Product " << i+1 << ": " << endl;
        cout << "ProductID: ";
        cin >> products[i].productID;
        cout << "Name: ";
        cin.ignore();
        getline(cin, products[i].name);
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price: ";
        cin >> products[i].price;
    }
}


void displayTotValue(Product* products, int n){
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += (float)products[i].quantity*products[i].price;
    }
    cout << "Total Value of Inventory: " << sum << endl;
}

void freeMemory(Product* products){
    delete[] products;
    cout << "Memory freed" << endl;
}


int main(){
    int size;
    cout << "Enter Size: ";
    cin >> size;

    Product* products = createProdInv(size);

    inputDetails(products, size);

    displayTotValue(products, size);

    freeMemory(products);

    return 0;
}