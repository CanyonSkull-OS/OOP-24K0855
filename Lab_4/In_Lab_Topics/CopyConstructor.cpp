#include <iostream>
using namespace std;



class shallowCopy{
    
    public:
        int* data = new int;


        shallowCopy(int value){
            *data = value;
        }

        shallowCopy(shallowCopy &obj){ //Shallow
            data = obj.data; //s2.data = s1.dataw
        }

        shallowCopy(shallowCopy *obj){ //Deep
            data = new int(*obj->data); //s2.data = s1.data
        }

        void display(){
            cout << "Value: " << *data << endl;
            cout << "Address: " << data << endl;
        }

};


int main(){
    shallowCopy *s1 = new shallowCopy(5);
    shallowCopy s2(s1);
    *s1->data = 10;

    s1->display();
    s2.display();
}