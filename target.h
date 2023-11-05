#ifndef TARGET
#define TARGET

#include <iostream>
#include "unit.h"

class Target : public Unit
{
public:
    Target(string n, int d, int a, selectedUnit s){
        name = n;
        damage = d;
        armor = a;
        unitType = s;
    }
    bool isDead(void);
    void lowerHealth(int);
};

#endif
