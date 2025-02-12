#include <iostream>
using namespace std;

class BMI{
    double weight, height, bmi;
    string status;

    public:
        void getInput(){
            cout << "Enter Weight in pounds: ";
            cin >> weight;
            cout << "Enter Height in inches: ";
            cin >> height;
        }

        double calcBMI(){
            return weight / (height * height) * 703;
        }

        string findStatus(){
            if (bmi < 18.5){
                return "Underweight";
            }
            else if (bmi < 25.0){
                return  "Normal";
            }
            else if (bmi < 29.9){
                return "Overweight";
            }
            return "Obese";
        }

        void printStatus(){
            bmi = calcBMI();

            cout << "Your BMI is: " << bmi << endl;
            cout << "Your status is: " << findStatus();
        }
};


int main(){
    BMI bmi;
    bmi.getInput();
    bmi.printStatus();

    return 0;
}