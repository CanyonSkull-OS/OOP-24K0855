#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main(){
    ifstream file("vehicles.txt");

    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)){
        if(line.empty()){
            continue;
        }
        cout << line << endl;
    }

    file.close();
    return 0;






}