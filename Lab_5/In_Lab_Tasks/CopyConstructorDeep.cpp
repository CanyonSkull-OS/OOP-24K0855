#include <iostream>
using namespace std;

class copyConstructor{

public:
    int *data;

    copyConstructor(int number){
        data = new int(number);
    }

    copyConstructor(const copyConstructor *obj){
        cout << "Hello" << endl;
        data = new int(*obj->data);
    }

    void display(){
        cout << "Data: " << *data << endl;
        cout << "Address: " << data << endl;
    }



};


int main(){
    copyConstructor *c1 = new copyConstructor(5);
    copyConstructor c2(c1);
    copyConstructor c3(&c2);

    c1->display();
    c2.display();
    c3.display();


    return 0;
}