#include "target.h"
#include "attacker.h"

enum selectedUnit{
    ZOOK, ATGUN, TANK
}selection;

Attacker* setAttacker(void);
Target* setTarget(void);

int main(void)
{
    srand(time(0));
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
    selection = (selectedUnit) select;
    switch(selection)
    {
        case ZOOK:
            return (new Attacker("Bazooka Squad", 50, 100));
            break;
        case ATGUN:
            return (new Attacker("Antitank Gun", 150, 150));
            break;
        case TANK:
            return (new Attacker("Tank", 200, 200));
            break;
    }
    return NULL;
}

Target* setTarget(void)
{
    int select;
    cout << "Select target unit: ";
    cin >> select;
    selection = (selectedUnit) select;
    switch(selection)
    {
        case ZOOK:
            return (new Target("Bazooka Squad", 50, 100));
            break;
        case ATGUN:
            return (new Target("Antitank Gun", 150, 150));
            break;
        case TANK:
            return (new Target("Tank", 200, 200));
            break;
    }
    return NULL;
}