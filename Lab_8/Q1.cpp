#include <iostream>
#include <cmath>
using namespace std;


class complex{
    int real;
    int imag;

    public:
    complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    complex operator+(complex obj){
        return complex(real + obj.real, imag + obj.imag);
    }
    
    complex operator-(complex obj){
        return complex(real - obj.real, imag - obj.imag);
    }

    complex operator*(complex obj){
        return complex(real * obj.real, imag * obj.imag);
    }

    complex operator/(complex obj){
        return complex(real / obj.real, imag / obj.imag);
    }

    friend ostream& operator<<(ostream& out, complex obj){
        out << "(" << obj.real << " + "  << obj.imag << "i)";
        return out;
    }

    friend double magnitude(complex& obj){
        return sqrt(obj.real * obj.real + obj.imag * obj.imag);
    }

};

int main(){
    complex a(3, 4);
    complex b(1, 2);

    complex sum = a + b;
    complex diff = a - b;
    complex prod = a * b;
    complex quot = a / b;

    cout << magnitude(a) << endl;
    cout << magnitude(b) << endl;

    return 0;
}