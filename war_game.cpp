#include "attacker.h"

#define INFANTRY_NAME "Infantry Squad"
#define INFANTRY_DAMAGE 50
#define INFANTRY_ARMOR 100
#define ATGUN_NAME "Antitank Gun"
#define ATGUN_DAMAGE 150
#define ATGUN_ARMOR 150
#define TANK_NAME "Tank"
#define TANK_DAMAGE 200
#define TANK_ARMOR 200

Attacker* setAttacker(void);
Target* setTarget(void);

int main(void)
{
    srand(time(0));         //  to seed RNG
    cout << "0:Bazooka Squad\n1:Antitank Gun\n2:Tank\n" << endl;
    Attacker* attackerUnit = setAttacker();     // create an attacker object
    Target* targetUnit = setTarget();           // create a target object

    while(targetUnit->getHealth() > 0)          // until target is down, keep attacking
    {
        attackerUnit->attack(targetUnit);
        for (long long int i=0; i<500000000; i++)   // some delay
            ;
    }

    /* print the result of the attack */
    cout << endl << attackerUnit->getName() << " killed the " << targetUnit->getName()
         << " in " << attackerUnit->getShotCount() << " shots...";

    /* release allocated memories */
    free(attackerUnit);
    free(targetUnit);

    return 0;
}


Attacker* setAttacker(void)
{
    int select;
    cout << "Select attacker unit: ";
    cin >> select;
    selection userSelection = (selectedUnit) select;
    switch(userSelection)
    {
        case INFANTRY:
            return (new Attacker(INFANTRY_NAME, INFANTRY_DAMAGE, INFANTRY_ARMOR, INFANTRY));
            break;
        case ATGUN:
            return (new Attacker(ATGUN_NAME, ATGUN_DAMAGE, ATGUN_ARMOR, ATGUN));
            break;
        case TANK:
            return (new Attacker(TANK_NAME, TANK_DAMAGE, TANK_ARMOR, TANK));
            break;
    }
    return NULL;
}

Target* setTarget(void)
{
    int select;
    cout << "Select target unit: ";
    cin >> select;
    selection userSelection = (selectedUnit) select;
    switch(userSelection)
    {
        case INFANTRY:
            return (new Target(INFANTRY_NAME, INFANTRY_DAMAGE, INFANTRY_ARMOR, INFANTRY));
            break;
        case ATGUN:
            return (new Target(ATGUN_NAME, ATGUN_DAMAGE, ATGUN_ARMOR, ATGUN));
            break;
        case TANK:
            return (new Target(TANK_NAME, TANK_DAMAGE, TANK_ARMOR, TANK));
            break;
    }
    return NULL;
}