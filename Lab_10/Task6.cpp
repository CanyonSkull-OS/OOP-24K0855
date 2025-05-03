#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
    
    public:
        int itemID;
        char itemName[20];
        InventoryItem(int ID, const char* name) : itemID(ID){
            strcpy(itemName, name);
        }
};


int main(){
    InventoryItem itemOut(123, "Laptop");
    
    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    outFile << itemOut.itemID << " " << itemOut.itemName << endl;
    outFile.close();

    InventoryItem itemIn(0, "");
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading." << endl;
        return 1;
    }
    inFile >> itemIn.itemID >> itemIn.itemName;
    inFile.close();

    cout << "Item ID: " << itemIn.itemID << endl;
    cout << "Item Name: " << itemIn.itemName << endl;

    return 0;
}