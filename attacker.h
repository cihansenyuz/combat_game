#ifndef ATTACKER_H
#define ATTACKER_H

#include <iostream>
#include "unit.h"
#include <time.h>   // to create RNG for damage calculation

#define ATTACK_BONUS 1.3

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
    void attack(Unit*);
    int getShotCount(void);
    
};

#endif