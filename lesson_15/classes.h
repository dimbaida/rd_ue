#include <iostream>
#include <vector>
#include <random>
#include <ctime> 
#include "utils.h"

using namespace std;

struct Fighter
{
    string name;
    int health;
    int damage;
    bool isAlive = true;

    string getPrettyName()
    {
        return "·" + name + " " + to_string(damage) + '/' + to_string(health) + "·";
    }
};

struct Clan
{
    vector<Fighter*> fighters;
    string name;

    void addFighter(Fighter &fighter)
    {
        fighters.push_back(&fighter);
    }

    void removeFighterByName(const string& name)
    {
        for (auto it = fighters.begin(); it != fighters.end();)
        {
            if ((*it)->name == name)
            {
                it = fighters.erase(it); 
            }
            else
            {
                ++it;
            }
        }
    }

    void removeDeadFighters()
    {
        for (auto it = fighters.begin(); it != fighters.end();)
        {
            if (!(*it)->isAlive)
            {
                it = fighters.erase(it);
            }
            else
            {
                ++it; 
            }
        }
    }


    Fighter* pickRandomFighter()
    {
        mt19937 rng(std::time(nullptr));
        uniform_int_distribution<std::size_t> dist(0, fighters.size() - 1);
        size_t random_index = dist(rng);
        return fighters[random_index];
    }
};


struct Arena
{
    array<Fighter*, 2> fighters;

    void announce(int& turn)
    {
        cout << "TURN " << turn << endl;
        string text = fighters[0]->getPrettyName() + " VS " + fighters[1]->getPrettyName();
        cout << framedText(text);
    }

    void fight()
    {
        fighters[0]->health -= fighters[1]->damage;
        fighters[1]->health -= fighters[0]->damage;
        fighters[0]->isAlive = fighters[0]->health > 0;
        fighters[1]->isAlive = fighters[1]->health > 0;
    }
};


void outputClanFigters(Clan &clan1, Clan &clan2)
{   
    clearConsole();
    if (clan1.fighters.size() > 0)
    {
        cout << clan1.name << " fighters:\n";
        for (Fighter* f : clan1.fighters)
        {
            cout << f->getPrettyName() << ' ';
        }
        cout << "\n" << endl;
    }

    if (clan2.fighters.size() > 0)
    {
        cout << clan2.name << " fighters:\n";
        for (Fighter* f : clan2.fighters)
        {
            cout << f->getPrettyName() << ' ';
        }
        cout << "\n" << endl;
    }
    cout << "=====================\n" << endl;
}