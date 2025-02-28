#include <iostream>
using namespace std;

class Print{
    protected:
        string brand;
        
    public:
        Print(string b) : brand(b){}

        void print(string doc){
            cout << "Printing " << doc << "........." << endl;
        }
};


class Scan{
    protected:
        int dpi;

    public:
        Scan(int d) : dpi(d){}

        void scan(string doc){
            cout << "Scanning " << doc << " at DPI: " << dpi << "........." << endl;
        }
};

class AllInOnePrinter : public Print, public Scan{
    protected:
        int paperCapacity;

    public:
        AllInOnePrinter(string b, int d, int pc) : Print(b), Scan(d), paperCapacity(pc){} 


        void copy(string doc){
            scan(doc);
            print(doc);
            cout << "Paper Capacity: " << paperCapacity << endl;
        }
};

int main(){
    AllInOnePrinter printer1("Suppo", 1000, 50);

    printer1.copy("Affan");



    return 0;
}