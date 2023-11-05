#ifndef UNIT
#define UNIT

#include <iostream>

using namespace std;

class Unit
{
protected:
    string name;
    int health = 100;
    int damage;
    int armor;
public:
    Unit(){}
    Unit(string n, int d, int a){
        name = n;
        damage = d;
        armor = a;
    }
    int getHealth(void);
    int getArmor(void);
    string getName(void);
};

#endif
