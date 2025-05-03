#include <iostream>
using namespace std;

class MenuItem{
    protected:
        string dishName;
        double price;

    public:
        MenuItem(string dishName, double price) : dishName(dishName), price(price) {}

        virtual void showDetails() = 0;
        virtual void prepare() = 0;
};

class Appetizer : public MenuItem{
    public:
        Appetizer(string dishName, double price) : MenuItem(dishName, price) {}

        void showDetails(){
            cout << "Appetizer: " << dishName << endl;
            cout << "Price: " << price << endl;
        }

        void prepare(){
            cout << "Preparing Appetizer: " << dishName << endl;
        }
};


class MainCourse : public MenuItem{
    public:
        MainCourse(string dishName, double price) : MenuItem(dishName, price) {}

        void showDetails(){
            cout << "Appetizer: " << dishName << endl;
            cout << "Price: " << price << endl;
        }

        void prepare(){
            cout << "Preparing MainCourse: " << dishName << endl;
        }
};

int main() {
    MenuItem *appetizer = new Appetizer("Shrimp Fries the Rice", 150);
    MenuItem *mainCourse = new MainCourse("Gummy bear", 20);

    appetizer->showDetails();
    appetizer->prepare();

    mainCourse->showDetails();
    mainCourse->prepare();

    return 0;
}