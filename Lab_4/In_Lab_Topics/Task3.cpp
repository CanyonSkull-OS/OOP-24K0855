#include <iostream>
using namespace std;


class Car{
    string brand;
    string model;
    double rentalPrice;
    bool status;
    int days;


    public:
        Car(){
            brand = "Unknown";
            model = "Generic";
            rentalPrice = 0.0;
            status = true;
        }
        
        Car(string b, string m, double p, bool s){
            brand = b;
            model = m;
            rentalPrice = p;
            status = s;
        }

        Car (Car &car1){
            brand = car1.brand;
            model = car1.model;
            rentalPrice = car1.rentalPrice;
            status = car1.status;
        }

        ~Car(){
            cout << "Destructor called" << endl;
        }

        bool checkAvailability(){
            return status;
        }

        void updateDetails(string b, string m, double p, bool s){
            brand = b;
            model = m;
            rentalPrice = p;
            cout << "Details Updated" << endl;
        }

        void processRentalReq(){
            cout << "Checking Availibility" << endl;
            if( status == true){
                status = false;
                cout << "Car Rented" << endl;
            }
            else{
                cout << "Request Denied" << endl;
            }
        }

        void applyDiscount(){
            if (days > 5 && days <= 10){
                rentalPrice = rentalPrice * 0.95;
            }
            else{
                rentalPrice = rentalPrice * 0.90;
            }
        }

};

int main(){
    Car car1("Toyota", "Corolla", 20000.0, true);
    Car car2(car1);

    

    return 0;
}