#include <iostream>
using namespace std;

class Vehicle{
    protected:
        string brand;
        int modelYear;

    public:
        Vehicle(string b, int m) : brand(b), modelYear(m){}


        void display(){
            cout << "-------------------" << endl;
            cout << "Car Brand: " << brand << endl;
            cout << "Model: " << modelYear << endl;
        }

};


class Car: public Vehicle{ //Vehicle -> Car
    protected:
        int numDoor;

    public:
        Car(string b, int m, int n) : Vehicle(b, m), numDoor(n){}


        void display(){
            Vehicle::display();
            cout << "Doors: " << numDoor << endl;
        }
};

class SportsCar : public Car{ //Vehicle -> Car -> SportsCar
    protected:
        int topSpeed;

    public:
        SportsCar(string b, int m, int n, int t) : Car(b, m, n), topSpeed(t){}

        void display(){
            Car::display();
            cout << "Top Speed: " << topSpeed << endl;
        }

};


int main(){
    SportsCar sc1("Toyota", 2003, 4, 130);

    sc1.display();

    return 0;
}