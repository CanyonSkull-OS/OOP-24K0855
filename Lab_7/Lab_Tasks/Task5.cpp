#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "") 
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks!" << endl;
    }

    virtual void defend() {
        cout << name << " defends!" << endl;
    }

    virtual void displayStats() {
        cout << "ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        if (!weaponType.empty()) {
            cout << "Weapon Type: " << weaponType << endl;
        }
    }

    void operator<<(Character& character) {
        character.displayStats();
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int damage, string weapon = "Sword") 
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " performs a powerful melee strike, dealing " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int spell, string weapon = "Staff") 
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " casts a magical barrier, reducing damage!" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy, string weapon = "Bow") 
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << name << " is out of arrows!" << endl;
        }
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agi, string weapon = "Dagger") 
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior1(101, "Thorin", 10, 150, 50, 30);
    Mage mage1(102, "Gandalf", 15, 100, 200, 40);
    Archer archer1(103, "Legolas", 12, 120, 20, 90);
    Rogue rogue1(104, "Ezio", 14, 110, 80, 95);

    warrior1.displayStats();
    cout << endl;
    mage1.displayStats();
    cout << endl;
    archer1.displayStats();
    cout << endl;
    rogue1.displayStats();
    
    warrior1.attack();
    mage1.defend();
    archer1.attack();
    rogue1.attack();

    warrior1 << mage1;

    return 0;
}
