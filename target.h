#ifndef TARGET_H
#define TARGET_H

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
    void counterAttack(Unit*);
};

#endif
