#include "attacker.h"

#define WEAK_TARGET 1.5
#define EQUAL_TARGET 1
#define STRONG_TARGET 0.25

int Attacker::getShotCount(void){
    return attackCount;
}

void Attacker::attack(Target* t){
    int damageDealt = (float)(((rand() % 20) + 90)/(float)100) *        // random number between 0.9 - 1.1
                        (getTargetMultiplier(t)) *                      // damage multiplier according to the target type
                        ((float)damage / (float)t->getArmor()) * 100;   // calculated damage upon attacker/target stats
    t->lowerHealth(damageDealt);                                        // lower the health of the target by damageDealt
    cout << name << " attacked " << t->getName() << "!! and did " << damageDealt << "HP damage!\n";
    attackCount++;
}

float Attacker::getTargetMultiplier(Target* t){
    
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
