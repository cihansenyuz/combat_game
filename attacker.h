#ifndef ATTACKER_H
#define ATTACKER_H

#include <iostream>
#include "unit.h"
#include "target.h"
#include <time.h>   // to create RNG for damage calculation

class Attacker : public Unit
{
private:
    int attackCount = 0;
public:
    Attacker(string n, int d, int a, selectedUnit s){
        name = n;
        damage = d;
        armor = a;
        unitType = s;
    }
    void attack(Target*);
    int getShotCount(void);
    float getTargetMultiplier(Target*);
};

#endif