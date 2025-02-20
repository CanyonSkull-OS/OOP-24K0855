#include <iostream>
using namespace std;


class Car{
    string brand;
    string model;
    double rentalPrice;
    bool status;
    int days;
    double totalRevenue;
    string registrationNumber;



    public:
        Car(){
            brand = "Unknown";
            model = "Generic";
            rentalPrice = 0.0;
            status = true;
            days = 0;
            totalRevenue = 0.0;
            registrationNumber = "ABC-123";
        }
        
        Car(string b, string m, double p, bool s, int d, double t, string r) :
        brand(b), model(m), rentalPrice(p),status(s), days(d), 
        totalRevenue(t), registrationNumber(r){}

        Car (const Car &car1) : brand(car1.brand), model(car1.model), 
        rentalPrice(car1.rentalPrice), status(car1.status), days(car1.days),
        totalRevenue(car1.totalRevenue), registrationNumber(car1.registrationNumber){}

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
            cout << "Enter Number of days: ";
            cin >> this->days;
            cout << "Checking Availibility" << endl;
            if( status == true){
                double newPrice = applyDiscount();
                this->totalRevenue += newPrice*days;
                this->status = false;
                cout << "Car Rented" << endl;
                returnCar();
            }
            else{
                cout << "Request Denied" << endl;
            }
        }

        double applyDiscount(){
            if (days > 5 && days <= 10){
                return rentalPrice * 0.95;
            }
            else if (days > 10){
                return rentalPrice * 0.90;
            }
            else{
                return rentalPrice;
            }
        }

        void trackTotalRevenue(){
            cout << "Total Revenue for " << brand << " " << model <<
            ": $" << this->totalRevenue << endl;
        }

        void displayCarDetails() {
            cout << "Car Details:" << endl;
            cout << "Registration Number: " << registrationNumber << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Rental Price per day: $" << rentalPrice << endl;
            cout << "Status: " << (status ? "Available" : "Rented") << endl;
            cout << "Total Revenue Generated: $" << totalRevenue << endl;
        }

        void returnCar(){
            status = true;
            cout << "Car with registration number " << registrationNumber <<
            " is available for rent again." << endl;
        }

};


#include <iostream>
using namespace std;

int main() {
    Car car1("Toyota", "Corolla", 20000.0, true, 9, 0.0, "ABC-124");

    car1.processRentalReq();
    
    car1.trackTotalRevenue();
    
    Car car2(car1);
    car2.trackTotalRevenue();
    
    car1.updateDetails("Honda", "Civic", 18000.0, true);
    
    car1.processRentalReq();

    car1.trackTotalRevenue();

    car1.displayCarDetails();

    return 0;
}
