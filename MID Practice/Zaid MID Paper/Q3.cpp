#include <iostream>
using namespace std;

class Vehicle{
    string brand;
    string model;
    float purchaseCost;


    public:
        Vehicle(string b, string m, float pc) : brand(b), 
        model(m), purchaseCost(pc){}

    void displayDetails(){
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Purchase Cost: " << purchaseCost << endl;
    }
};


class Rentable : public Vehicle{
    float rentalCost;

    public:
        Rentable(string b, string m, float pc, float rc) : Vehicle(b, m, pc),
        rentalCost(rc){}

        float calculateRentalCost(){
            return rentalCost;
        }
};

class OperationalVehicle : public Vehicle{
    string operationZone;

    public:
        OperationalVehicle(string b, string m, float pc, string oz) : Vehicle(b, m, pc),
        operationZone(oz){}

        void displayOpertaionalDetails(){
            displayDetails();
            cout << "Operation Zone: " << operationZone << endl;
        }
};

class MaintenanceTruck : public Rentable{
    float liftHeight;
    float loadCapacity;

    public:
        MaintenanceTruck(string b, string m, float pc, float rc, float lh, float lc) : 
        Rentable(b, m, pc, rc), liftHeight(lh), loadCapacity(lc){}

        void displayDetails(){
            Vehicle::displayDetails();
            cout << "Lift Height: " << liftHeight << endl;
            cout << "Load Capacity: " << loadCapacity << endl;
            cout << "Rental Cost: " << calculateRentalCost() << endl;
            cout << endl;
        }

};

class EmergencyResponseVan : public Rentable{
    int emergencyEquipmentCount;
    float responseSpeed;

    public:
        EmergencyResponseVan(string b, string m, float pc, float rc, int eec, float rs) : 
        Rentable(b, m, pc, rc), emergencyEquipmentCount(eec), responseSpeed(rs){}

        void displayDetails(){
            Vehicle::displayDetails();
            cout << "Emergency Equipment Load: " << emergencyEquipmentCount << endl;
            cout << "Response Speed: " << responseSpeed << endl;
            cout << "Rental Cost: " << calculateRentalCost() << endl;
            cout << endl;
        }
};

class MeterInspectionBike : public Rentable{
    float fuelEfficiency;
    float storageCapacity;

    public:
        MeterInspectionBike(string b, string m, float pc, float rc, float fe, float sc) : 
        Rentable(b, m, pc, rc), fuelEfficiency(fe), storageCapacity(sc){}

        void displayDetails(){
            Vehicle::displayDetails();
            cout << "Fuel Efficiency: " << fuelEfficiency << endl;
            cout << "Storage Capacity: " << storageCapacity << endl;
            cout << "Rental Cost: " << calculateRentalCost() << endl;
            cout << endl;
        }
};      

int main(){
    MeterInspectionBike mb1("Toyota", "Corolla", 300, 30, 10.2, 1.3);
    EmergencyResponseVan erv1("honda", "civic", 400, 10, 10, 14.1);
    MaintenanceTruck mt1("suzuki", "alto", 600, 5, 100, 51);

    mb1.displayDetails();
    erv1.displayDetails();
    mt1.displayDetails();

    return 0;
}

