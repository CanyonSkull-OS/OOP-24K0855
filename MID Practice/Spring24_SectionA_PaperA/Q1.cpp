#include <iostream>
#include <math.h>
using namespace std;

class FinancialStatistics{
    int size;
    double* Array;
    double mean;
    double total;

public:
    FinancialStatistics(int s, double* arr, double m, double t) 
        : size(s), mean(m), total(t) {
        Array = new double[size];
        for (int i = 0; i < size; i++) {
            Array[i] = arr[i];
        }
    }

    double calculateMean() {
        total = 0;
        for (int i = 0; i < size; i++) {
            total += Array[i];
        }
        mean = total / size;
        return mean;
    }

    double getVariance() {
        if (size <= 1) return 0;
        double temp = 0;
        for (int i = 0; i < size; i++) {
            temp += pow(Array[i] - mean, 2);
        }
        return temp / (size - 1);
    }

    ~FinancialStatistics() {
        delete[] Array;
    }
};

int main() {
    int size;
    cin >> size;
    
    double* arr = new double[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    FinancialStatistics FS(size, arr, 0, 0);
    

    cout << "Mean: " << FS.calculateMean() << endl;
    cout << "Variance: " << FS.getVariance() << endl;

    delete[] arr;
}
