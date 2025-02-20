#include <iostream>
using namespace std;


class Car{
    string brand;
    string model;
    double rentalPrice;
    bool status;


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

        void applyDiscount(int days){
            if (days > 5 && days <= 10){
                rentalPrice = rentalPrice * 0.95;
            }
            else{
                rentalPrice = rentalPrice * 0.90;
            }
        }

};

int main(){
    Car car1;
    Car car2("Honda", "Civic", 3000.0, true);

    if(car1.checkAvailability()){
        cout << "Car is Available" << endl;
    }
    else{
        cout << "Car not available" << endl;
    }

    car1.updateDetails("Toyota", "Corolla", 2000.0, true);

    car1.processRentalReq();

    if(car2.checkAvailability()){
        cout << "Car is Available" << endl;
    }
    else{
        cout << "Car not available" << endl;
    }

    car2.applyDiscount(8);

    car2.processRentalReq();

    return 0;
}