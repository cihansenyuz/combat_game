#include "attacker.h"

int Attacker::getShotCount(void){
    return attackCount;
}

void Attacker::attack(Unit* t){
    int damageDealt = (float)(((rand() % 20) + 90)/(float)100) *        // random number between 0.9 - 1.1
                        ATTACK_BONUS *                                  
                        (getTargetMultiplier(t)) *                      // damage multiplier according to the target type
                        ((float)damage / (float)t->getArmor()) * 100;   // calculated damage upon attacker/target stats
    t->lowerHealth(damageDealt);                                        // lower the health of the target by damageDealt
    cout << name << " attacked " << t->getName() << "!! and did " << damageDealt << "HP damage!\n";
    attackCount++;
}

