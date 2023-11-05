#ifndef ATTACKER
#define ATTACKER

#include <iostream>
#include "unit.h"
#include "target.h"
#include <time.h>   // to create RNG for damage calculation

class Attacker : public Unit
{
private:
    int attackCount = 0;
public:
    Attacker(string n, int d, int a){
        name = n;
        damage = d;
        armor = a;
    }
    void attack(Target*);
    int getShotCount(void);
};

#endif