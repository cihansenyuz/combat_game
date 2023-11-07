#include "attacker.h"
#include "target.h"

#define INFANTRY_NAME "Infantry Squad"
#define INFANTRY_DAMAGE 50
#define INFANTRY_ARMOR 100
#define ATGUN_NAME "Antitank Gun"
#define ATGUN_DAMAGE 150
#define ATGUN_ARMOR 150
#define TANK_NAME "Tank"
#define TANK_DAMAGE 200
#define TANK_ARMOR 200

void start_message(void);
Attacker* setAttacker(void);
Target* setTarget(void);

int main(void)
{
    start_message();
    Attacker* attackerUnit = setAttacker();                     // create an attacker object

    while(!attackerUnit->isDead())                       // until we are dead, keep playing
    {
        srand(time(0));                                     //  to seed RNG
        Target* targetUnit = setTarget();                   // create a target object
        cout << "0:Infantry Squad\n1:Antitank Gun\n2:Tank\n" << endl;

        while(!targetUnit->isDead())                        // until target is down, keep attacking
        {
            for (long long int i=0; i<500000000; i++)       // some delay
                ;
            
            attackerUnit->attack(targetUnit);
            if(targetUnit->isDead())                        // if target is down, exit loop
            {
                /* print the result of the attack */
                cout << endl << "Ally " << attackerUnit->getName() << " killed the enemy" << targetUnit->getName()
                << " in " << attackerUnit->getShotCount() << " shots..." << endl;
                break;
            }

            targetUnit->counterAttack(attackerUnit);
            if(attackerUnit->isDead())                      // if attacker is down, print the result, exit loop
            {
                cout << endl << "Enemy "<< targetUnit->getName() << " killed our " << attackerUnit->getName()
                 << " in the counter-attack!" << endl;
                break;
            }
        }
        free(targetUnit);
    }
    cout << endl << "/// GAME IS OVER ///" << endl;
    
    /* release allocated memories */
    //free(attackerUnit);
    //free(targetUnit);

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
            return (new Attacker(INFANTRY_NAME, INFANTRY_DAMAGE, INFANTRY_ARMOR, INFANTRY)); break;
        case ATGUN:
            return (new Attacker(ATGUN_NAME, ATGUN_DAMAGE, ATGUN_ARMOR, ATGUN)); break;
        case TANK:
            return (new Attacker(TANK_NAME, TANK_DAMAGE, TANK_ARMOR, TANK)); break;
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
            return (new Target(INFANTRY_NAME, INFANTRY_DAMAGE, INFANTRY_ARMOR, INFANTRY)); break;
        case ATGUN:
            return (new Target(ATGUN_NAME, ATGUN_DAMAGE, ATGUN_ARMOR, ATGUN)); break;
        case TANK:
            return (new Target(TANK_NAME, TANK_DAMAGE, TANK_ARMOR, TANK)); break;
    }
    return NULL;
}

void start_message(void)
{
    cout << "/// COMBAT GAME ///\n You will select your attacker unit and targets\n" <<
    "once your unit dies, the game is over\n" << endl;
    cout << "0:Infantry Squad\n1:Antitank Gun\n2:Tank\n" << endl;
}