#ifndef ATTACKER
#define ATTACKER

#include <iostream>
#include "unit.h"
#include "target.h"

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