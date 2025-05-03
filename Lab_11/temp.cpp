#include <iostream>
using namespace std;


class TemplateClass{
    public:
        template <typename T, typename U>


        void printValue(T a, U b){
            cout << "Addtion of " << a << " and " << b << " is: " << a + b << endl;
        }
};

int main(){

    TemplateClass t1;

    t1.printValue<int, double>(5, 25.5);

    return 0;
}