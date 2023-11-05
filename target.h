#ifndef TARGET
#define TARGET

#include <iostream>
#include "unit.h"

class Target : public Unit
{
public:
    Target(string n, int d, int a){
        name = n;
        damage = d;
        armor = a;
    }
    bool isDead(void);
    void lowerHealth(int);
    int getHealth(void);
};

#endif
