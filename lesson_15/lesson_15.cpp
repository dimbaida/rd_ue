#include <iostream>
#include <vector>
#include "classes.h"

void outputHeader(Clan& clan1, Clan& clan2);

int main()
{
    Clan clan_01, clan_02;
    clan_01.name = "Sigurdsson Clan";
    clan_02.name = "Yngling Clan";

    Fighter fighter1("Ragnar", 15, 90);
    Fighter fighter2("Bjorn", 11, 110);
    Fighter fighter3("Astrid", 14, 100);
    Fighter fighter4("Leif", 8, 140);

    clan_01.addFighter(fighter1);
    clan_01.addFighter(fighter2);
    clan_02.addFighter(fighter3);
    clan_02.addFighter(fighter4);

    while (true)
    {
        outputHeader(clan_01, clan_02);

        int action;
        cout    << "[0] - add fighter\n"
                << "[1] - remove fighter\n"
                << "[2] - start fight" << endl
                << "Choose your action: ";
        cin     >> action;
        
        switch (action)
        {
            case 0:  // add fighter
            {
                Fighter fighter;

                outputHeader(clan_01, clan_02);
                cout << "Clan [0] or [1]: ";
                int clan_id;
                cin >> clan_id;
                Clan &clan = clan_id ? clan_02 : clan_01;

                outputHeader(clan_01, clan_02);
                cout << "Name: ";
                cin >> fighter.name;
                
                outputHeader(clan_01, clan_02);
                cout << "Health: ";
                cin >> fighter.health;

                outputHeader(clan_01, clan_02);
                cout << "Damage: ";
                cin >> fighter.damage;

                clan.addFighter(fighter);
                break;
            }

            case 1:  // remove fighter
            {
                outputHeader(clan_01, clan_02);
                string name;
                cout << "Enter fighter's name: ";
                cin >> name;
                clan_01.removeFighterByName(name);
                clan_02.removeFighterByName(name);
                break;
            }

            case 2:  // fight
            {   
                int turn;
                Arena arena;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (clan_01.fighters.size() > 0 && clan_02.fighters.size() > 0)
                {
                    turn++;
                    outputHeader(clan_01, clan_02);
                    cout << "TURN " << turn << endl;
                    arena.fighters[0] = clan_01.pickRandomFighter();
                    arena.fighters[1] = clan_02.pickRandomFighter();
                    arena.announce();
                    cin.get();
                    arena.fight();
                    clan_01.removeDeadFighters();
                    clan_02.removeDeadFighters();
                }

                outputHeader(clan_01, clan_02);
                cout << "TURN " << turn << endl;

                if (clan_01.fighters.size() == 0 && clan_02.fighters.size() == 0)
                    cout << "No one wins. Everybody is dead." << endl;
                else if (clan_01.fighters.size() == 0)
                    cout << clan_02.name << " wins!" << endl;
                else
                    cout << clan_01.name << " wins!" << endl;
                cin.get();
                return 0;
            }
            
            default:
                break;
        }
    }
    return 0;       
}

void outputHeader(Clan& clan1, Clan& clan2)
{   
    clearConsole();

    if (clan1.fighters.size() > 0)
    {
        cout << clan1.name << " fighters:\n";
        for (Fighter* f : clan1.fighters)
            cout << f->getPrettyName() << ' ';
        cout << "\n" << endl;
    }

    if (clan2.fighters.size() > 0)
    {
        cout << clan2.name << " fighters:\n";
        for (Fighter* f : clan2.fighters)
            cout << f->getPrettyName() << ' ';
        cout << "\n" << endl;
    }

    cout << "==========================\n" << endl;
}