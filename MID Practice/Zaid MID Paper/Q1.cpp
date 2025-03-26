#include <iostream>
#include <string.h>
using namespace std;

class Car{
    private:
        const int CarID;
        string model;
        double price;
        char* mName;
        int carCount;

    public:
        Car(int cID, string m, double p, const char* mn, int cC) : CarID(cID),
        model(m), price(p), carCount(cC){
            mName = new char[strlen(mn) + 1];
            strcpy(mName, mn);
        }

        Car(const Car &obj): CarID(obj.CarID), model(obj.model), price(obj.price),
        carCount(obj.carCount){
            mName = new char[strlen(obj.mName) + 1];
            strcpy(mName, obj.mName);
        }

        ~Car(){
            delete[] mName;
        }

        int getCarID(){return CarID;}
        string getModel(){return model;}
        double getprice(){return price;}
        char* getMName(){return mName;}
        int getCarCount(){return carCount;}
};


int main(){
    const char* name1 = "Suzuki";
    const char* name2 = "Toyota";
    Car cars[2] = {
        Car(1, "Suzuki Alto", 30000, name1, 3),
        Car(2, "Toyota Corolla", 50000, name2, 2)
    };
    int total = 0;
    for (int i = 0; i < 2; i++)
    {
        total += cars[i].getCarCount();
    }
    cout << "Total cars in inventory: " << total << endl;

    int carid;
    bool found = false;
    cout << "Enter Car ID: ";
    cin >> carid;
    for (int i = 0; i < 2; i++)
    {
        if(carid == cars[i].getCarID()){
            found = true;
            cout << cars[i].getModel() << endl;
            cout << cars[i].getprice() << endl;
            cout << cars[i].getMName() << endl;
            break;
        }
    }
    if(!found){
        cout << "Car not found" << endl;
    }

    Car hellokittycar(cars[1]);

    cout << hellokittycar.getModel() << endl;
    cout << hellokittycar.getprice() << endl;
    cout << hellokittycar.getMName() << endl;
    

    return 0;
}