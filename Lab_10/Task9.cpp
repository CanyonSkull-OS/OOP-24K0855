#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("large_log.txt");
    outFile << "This is the first pasrt of the log\n" << "This is the second part of the log\n" <<
    "And the Third part\n" << endl;
    outFile.close();

    ifstream inFile("large_log.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line1, line2, line3;

    getline(inFile, line1);
    cout << "First line: " << line1 << endl;
    cout << "Position after first getline: " << inFile.tellg() << endl;

    getline(inFile, line2);
    cout << "Second line: " << line2 << endl;
    cout << "Position after second getline: " << inFile.tellg() << endl;
    
    getline(inFile, line3);
    cout << "Third line: " << line3 << endl;
    cout << "Position after third getline: " << inFile.tellg() << endl;

    inFile.close();
    return 0;
}
