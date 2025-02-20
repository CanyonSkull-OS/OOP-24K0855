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

        bool checkAvailability(){
            return status;
        }

        void updateDetails(string b, string m, double p){
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

};

int main(){
    Car car1;

    if(car1.checkAvailability()){
        cout << "Car is Available" << endl;
    }
    else{
        cout << "Car not available" << endl;
    }

    car1.updateDetails("Toyota", "Corolla", 2000.0);

    car1.processRentalReq();
    car1.processRentalReq();

    return 0;
}