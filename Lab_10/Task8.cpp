#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("config.txt");
    if (!outFile) {
        cout << "Error creating file." << endl;
        return 1;
    }

    outFile << "AAAAA" << "BBBBB" << "CCCCC";
    outFile.close();
    cout << "Initial data written.\n";

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    file.seekp(5);

    file << "XXXXX";
    file.close();

    ifstream inFile("config.txt");
    if (!inFile) {
        cout << "Error opening file for reading." << endl;
        return 1;
    }

    string contents;
    getline(inFile, contents);
    cout << "File contents: " << contents << endl;

    inFile.close();
    return 0;
}