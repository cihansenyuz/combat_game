#include "attacker.h"

int Attacker::getShotCount(void)
{
    return attackCount;
}

void Attacker::attack(Target* t)
{
    int damageDealt = ((float)damage / (float)t->getArmor()) * 100;
    t->lowerHealth(damageDealt);
    cout << name << " attacked " << t->getName() << "!! and did " << damageDealt << "HP damage!\n";
    attackCount++;
}
