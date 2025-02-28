#include <iostream>
using namespace std;

class Vehicle{
    protected:
        string brand;
        int speed;


    public:
        Vehicle(string b, int sp) : brand(b), speed(sp){}

        void display(){
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
        }

};
class Car : public Vehicle{
    protected:
        int seats;


    public:
        Car(string b, int sp, int s) : Vehicle(b, sp), 
            seats(s){}

        void display(){
            Vehicle::display();
            cout << "Seats: " << seats << endl;
        }
};

class ElectricCar : public Car{
    protected:
        int batteryLife;

    public:
        ElectricCar(string b, int sp, int s, int bl) : Car(b, sp, s),
            batteryLife(bl){}


        void display(){
            Car::display();
            cout << "Battery Life: " << batteryLife << endl;
        }
};

int main(){
    ElectricCar ec1("Audi", 200, 6, 100);
    ec1.display();
}