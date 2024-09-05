#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;


int main()
{
    Clan clan_01, clan_02;
    clan_01.name = "Sigurdsson Clan";
    clan_02.name = "Yngling Clan";

    Fighter fighter1;
    fighter1.name = "Ragnar";
    fighter1.damage = 15;
    fighter1.health = 90;
    Fighter fighter2;
    fighter2.name = "Bjorn";
    fighter2.damage = 11;
    fighter2.health = 110;
    Fighter fighter3;
    fighter3.name = "Astrid";
    fighter3.damage = 14;
    fighter3.health = 100;
    Fighter fighter4;
    fighter4.name = "Leif";
    fighter4.damage = 8;
    fighter4.health = 140;

    clan_01.addFighter(fighter1);
    clan_01.addFighter(fighter2);
    clan_02.addFighter(fighter3);
    clan_02.addFighter(fighter4);


    while (true)
    {
        outputClanFigters(clan_01, clan_02);

        int action;
        cout    << "0 - add fighter\n"
                << "1 - remove fighter\n"
                << "2 - start fight" << endl
                << "Choose your action: ";
        cin     >> action;
        
        switch (action)
        {
            case 0:  // add fighter
            {
                Fighter fighter;

                outputClanFigters(clan_01, clan_02);
                cout << "Clan [0] or [1]: ";
                int clan_id;
                cin >> clan_id;
                Clan &clan = clan_id ? clan_02 : clan_01;

                outputClanFigters(clan_01, clan_02);
                cout << "Name: ";
                cin >> fighter.name;
                
                outputClanFigters(clan_01, clan_02);
                cout << "Health: ";
                cin >> fighter.health;

                outputClanFigters(clan_01, clan_02);
                cout << "Damage: ";
                cin >> fighter.damage;

                clan.addFighter(fighter);
                break;
            }

            case 1:  // remove fighter
            {
                outputClanFigters(clan_01, clan_02);
                string name;
                cout << "Enter fighter's name: ";
                cin >> name;
                clan_01.removeFighterByName(name);
                clan_02.removeFighterByName(name);
                break;
            }

            case 2:  // fight
            {   
                int turn = 1;
                while (clan_01.fighters.size() > 0 && clan_02.fighters.size() > 0)
                {
                    outputClanFigters(clan_01, clan_02);
                    Arena arena;
                    arena.fighters[0] = clan_01.pickRandomFighter();
                    arena.fighters[1] = clan_02.pickRandomFighter();
                    arena.announce(turn);
                    cin.get();
                    arena.fight();
                    clan_01.removeDeadFighters();
                    clan_02.removeDeadFighters();
                    turn++;
                }

                if (clan_01.fighters.size() == 0 && clan_02.fighters.size() == 0)
                {
                    outputClanFigters(clan_01, clan_02);
                    cout << framedText("No one wins. Tie.") << endl;
                }
                else if (clan_01.fighters.size() == 0)
                {
                    outputClanFigters(clan_01, clan_02);
                    cout << framedText(clan_02.name + " wins!") << endl;
                }
                else
                {
                    outputClanFigters(clan_01, clan_02);
                    cout << clan_01.name + " wins!" << endl;
                }
                cin.get();
                return 0;
                
            }
            
            default:
            {
                break;
            }

        }

    }

    return 0;       
}