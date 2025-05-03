#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    
    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    string data1 = "Sensor 1: 25.5 C";
    outFile << data1 << endl;
    int pos1 = outFile.tellp();
    cout << "Position after writing data1: " << pos1 << endl;

    string data2 = "Sensor 2: 98.1 %RH";
    outFile << data2 << endl;
    int pos2 = outFile.tellp();
    cout << "Position after writing data2: " << pos2 << endl;

    outFile.close();

    return 0;
}
