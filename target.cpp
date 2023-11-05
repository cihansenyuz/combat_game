#include "target.h"

bool Target::isDead(void){
    if(health <= 0)
        return true;
    return false;
}

void Target::lowerHealth(int h){
    health -= h;
}

