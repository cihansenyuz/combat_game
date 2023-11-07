#include "target.h"

void Target::counterAttack(Unit* a){
    int damageDealt = (float)(((rand() % 20) + 90)/(float)100) *        // random number between 0.9 - 1.1
                        (this->getTargetMultiplier(a)) *                      // damage multiplier according to the target type
                        ((float)damage / (float)a->getArmor()) * 100;   // calculated damage upon attacker/target stats
    a->lowerHealth(damageDealt);    
    cout << "Counter-attack recieved!! and did " << damageDealt << "HP damage!\n";
}
