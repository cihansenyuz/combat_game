#ifndef UNIT_H
#define UNIT_H

#include <iostream>

using namespace std;

enum selectedUnit{
    INFANTRY, ATGUN, TANK
}selection;

class Unit
{
protected:
    string name;
    int health = 100;
    int damage;
    int armor;
    int unitType;
public:
    Unit(){}
    Unit(string n, int d, int a){
        name = n;
        damage = d;
        armor = a;
    }
    int getHealth(void);
    int getArmor(void);
    int getUnitType(void);
    string getName(void);
};

#endif
