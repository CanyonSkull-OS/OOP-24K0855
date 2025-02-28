#include <iostream>
using namespace std;

class Device{
    protected:
        int deviceID;
        bool status;

    public:
        Device(int id) : deviceID(id), status(false){}

        void display(){
            cout << "Device ID: " << deviceID << endl;
            cout << "Device Status: " << status << endl;
        }
};

class SmartPhone : public Device{
    protected:
        float screenSize;

    public:
        SmartPhone(int id, float ss) : Device(id), screenSize(ss){}

        void display(){
            Device::display();
            cout << "Screen Size: " << screenSize << endl;
        }

};


class SmartWatch : public Device{
    public:
        bool heartRateMonitor;

    public:
        SmartWatch(int id, bool hrm) : Device(id), heartRateMonitor(hrm){}

        void display(){
            Device::display();
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
        }

};


class SmartWearable : public SmartPhone, public SmartWatch{
    protected:
        int stepCounter;

    public:
        SmartWearable(int id, bool hrm, float ss, int sc) : SmartPhone(id, ss),
            SmartWatch(id, hrm), stepCounter(sc){}

        void display(){
            SmartPhone::display();
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
            cout << "Steps Taken: " << stepCounter << endl;
        }
};

int main(){
    SmartWearable sw1(104, true, 5.5, 10000);

    sw1.display();

    return 0;
}