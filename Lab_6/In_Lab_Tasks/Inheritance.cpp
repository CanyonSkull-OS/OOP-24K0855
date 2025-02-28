#include <iostream>
using namespace std;


class Base{
    protected:
        int a;
        int b;

    public:
        Base(int a, int b) : a(a), b(b){}


};
    
class Derived : public Base{ //Sub Class 1
    int c;
    
    public:
    Derived(int a, int b, int c) : Base(a,b), c(c){}
    
    void display(){
        cout << "A: " << a << endl;
        cout << "B: " << b << endl;
        cout << "C: " << c << endl;
    }
};

class Derived2 : public Base{ //Sub Class 1
    public:

};


int main(){
    Derived d1(15,10, 20);
    d1.display();



    return 0;
}