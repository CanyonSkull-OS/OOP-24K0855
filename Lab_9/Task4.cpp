#include <iostream>
using namespace std;


class WeatherSensor{
    public:
        virtual void readData() = 0;
        virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor{
    public:
        void readData() override{
            cout << "Reading data from thermometer" << endl;
        }
        void displayReport() override{
            cout << "Displaying report from thermometer" << endl;
        }
};

class Barometer : public WeatherSensor{
    public:
        void readData() override{
            cout << "Reading data from barometer" << endl;
        }
        void displayReport() override{
            cout << "Displaying report from barometer" << endl;
        }
};

int main(){
    Thermometer thermometer;
    Barometer barometer;

    thermometer.readData();
    thermometer.displayReport();

    barometer.readData();
    barometer.displayReport();

    return 0;
}