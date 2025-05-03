#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
using namespace std;

int main(){
    ifstream file("vehicles.txt");

    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    string vehicleType, vehicleID ,vehicleName, vehicleYear, ExtraData, Certification;

    while (getline(file, line)){
        if(line.empty()){
            continue;
        }
        istringstream L(line);

        
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
        cout << "\n\n";

    }

    int vehicleY = stoi(vehicleYear);
    cout << "String converted to int: " << vehicleY << endl;

    file.close();
    return 0;


}