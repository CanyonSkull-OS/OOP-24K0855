#include <iostream>
using namespace std;

class Room {
private:
    string roomType;

public:
    Room(string type) : roomType(type) {}

    void displayRoom() const {
        cout << "Room Type: " << roomType << endl;
    }
};

class House {
private:
    string houseName;
    Room LivingRoom;
    Room bedroom;

public:
    House(string name, string lrType, string brType)
        : houseName(name), LivingRoom(lrType), bedroom(brType) {}

    void displayHouse() const {
        cout << "House Name: " << houseName << endl;
        LivingRoom.displayRoom();
        bedroom.displayRoom();
    }
};

int main() {
    House MyHouse("Dream Villa", "Living Room", "Master Bedroom");
    MyHouse.displayHouse();
    return 0;
}