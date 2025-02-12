#include <iostream>
using namespace std;


class Car{
    string brand;
    string model;
    int fuelCapacity = 15;
    double fuelLevel;

    public:
        void driveCar(double km){
            fuelLevel -= km/20;
            if (fuelLevel > 0){
                cout << "Fuel Consumed" << endl;
            }
            if (fuelLevel < 2){
                cout << "Fuel Low. Kindly refill or you will die" << endl;
            }
            
        }

        void refuelTank(){
            fuelLevel = fuelCapacity;
            cout << "Fuel Refilled" << endl;
        }

        double checkFuel(){
            return fuelLevel;
        }

};

int main(){
    Car car1;

    car1.refuelTank();

    car1.driveCar(100);

    car1.driveCar(150);

    cout << "Fuel: " << car1.checkFuel() << endl;

    return 0;
}