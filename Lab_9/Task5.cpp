#include <iostream>
using namespace std;

class Shipment{
    string trackingNumber;
    double weight;

    public:
        virtual void estimateDeliveryTime() = 0;
        virtual void showDetails() = 0;

};

class AirFrieght : public Shipment{
    public:
        void estimateDeliveryTime() override{
            cout << "Estimated delivery time: 3 days" << endl;
        }
        void showDetails() override{
            cout << "Air Freight" << endl;
        }
};

class GroundShipment : public Shipment{
    public:
        void estimateDeliveryTime() override{
            cout << "Estimated delivery time: 5 days" << endl;
        }
        void showDetails() override{
            cout << "Ground Shipment" << endl;
        }
};

int main() {
    AirFrieght airFrieght;
    GroundShipment groundShipment;

    airFrieght.estimateDeliveryTime();
    airFrieght.showDetails();

    groundShipment.estimateDeliveryTime();
    groundShipment.showDetails();


    return 0;
}