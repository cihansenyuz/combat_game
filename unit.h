#ifndef UNIT_H
#define UNIT_H

#include <iostream>

/* define target damage multipliers */
#define WEAK_TARGET 1.5
#define EQUAL_TARGET 1
#define STRONG_TARGET 0.25

using namespace std;

typedef enum selectedUnit{
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
    Unit(string n, int d, int a, selectedUnit s){
        name = n;
        damage = d;
        armor = a;
        unitType = s;
    }
    int getHealth(void);
    int getArmor(void);
    int getUnitType(void);
    string getName(void);
    float getTargetMultiplier(Unit*);
    void lowerHealth(int);
    bool isDead(void);
};

#endif
