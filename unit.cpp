#include "unit.h"

int Unit::getHealth(void){
    return health;
}

int Unit::getArmor(void){
    return armor;
}

string Unit::getName(void){
    return name;
}

int Unit::getUnitType(void){
    return unitType;
}

float Unit::getTargetMultiplier(Unit* t){
    
    if(unitType == INFANTRY)
    {
        switch(t->getUnitType())
        {
            case INFANTRY:
                return EQUAL_TARGET; break;
            case ATGUN:
                return WEAK_TARGET; break;
            case TANK:
                return STRONG_TARGET; break;
        }
    }
    else if(unitType == ATGUN)
    {
        switch(t->getUnitType())
        {
            case INFANTRY:
                return STRONG_TARGET; break;
            case ATGUN:
                return EQUAL_TARGET; break;
            case TANK:
                return WEAK_TARGET; break;
        }
    }
    else // (unitType == TANK)
    {
        switch(t->getUnitType())
        {
            case INFANTRY:
                return WEAK_TARGET; break;
            case ATGUN:
                return STRONG_TARGET; break;
            case TANK:
                return EQUAL_TARGET; break;
        }
    }
    cout << "ERROR! not a valid target" << endl;
    return 1;
}

void Unit::lowerHealth(int h){
    health -= h;
}

bool Unit::isDead(void){
    if(health <= 0)
        return true;
    return false;
}
