#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("data_records.txt");
    outFile << "Record 1" << endl << "Record 2" << endl <<
    "Record 3" << endl << "Record 4" << endl;;
    outFile.close();

    ifstream inFile("data_records.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    streampos offset = 20;
    inFile.seekg(offset, ios::beg);

    string targetRecord;
    getline(inFile, targetRecord);

    cout << "Third record: " << targetRecord << endl;

    inFile.close();
    return 0;
}
