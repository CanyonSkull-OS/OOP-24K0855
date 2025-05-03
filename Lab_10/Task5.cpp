#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty() || line.rfind("//", 0) == 0) {
            continue; // Skip comments and empty lines
        }

        istringstream L(line);
        string vehicleType, vehicleID, vehicleName, vehicleYear, ExtraData, Certification;

        getline(L, vehicleType, ',');
        getline(L, vehicleID, ',');
        getline(L, vehicleName, ',');
        getline(L, vehicleYear, ',');
        getline(L, ExtraData, ',');
        getline(L, Certification, ',');

        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Vehicle Name: " << vehicleName << endl;
        cout << "Vehicle Year: " << vehicleYear << endl;
        cout << "Extra Data: " << ExtraData << endl;
        cout << "Certification: " << Certification << endl;

        int colonPos = ExtraData.find(':');
        if (colonPos != string::npos) {
            string numberPart = ExtraData.substr(colonPos + 1);  // Extract number part

            if (vehicleType == "AutonomousCar") {
                float softwareVersion = stof(numberPart);
                cout << "Software Version: " << softwareVersion << endl;
            } 
            else if (vehicleType == "ElectricVehicle") {
                int batteryCapacity = stoi(numberPart);
                cout << "Battery Capacity: " << batteryCapacity << endl;
            }
            else if (vehicleType == "HybridTruck") {
                int pipePos = numberPart.find("|");
                if (pipePos != string::npos){
                    int numberPart1 = stoi(ExtraData.substr(colonPos + 1, pipePos));
                    cout << "Cargo Capacity: " << numberPart1 << endl;
                }
                int colonPos2 = numberPart.find(':');
                if (colonPos2 != string::npos){
                    int numberPart2 = stoi(numberPart.substr(colonPos2 + 1));
                    cout << "Battery Capacity: " << numberPart2 << endl;
                }
            }
            else {
                cout << "Unknown vehicle type" << endl;
            }
        }   

        cout << "\n\n";
    }

    file.close();
    return 0;
}
