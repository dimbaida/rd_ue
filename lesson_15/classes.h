#include <iostream>
#include <vector>
#include <random>
#include <ctime> 
#include <string>
#include <array>
#include "utils.h"

using namespace std;

struct Fighter
{
    string name;
    int health;
    int damage;
    bool isAlive = true;

    Fighter() : name("Unknown"), damage(10), health(100) {};
    Fighter(string n, int d, int h) : name(n), damage(d), health(h) {};
    
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
                it = fighters.erase(it); 
            else
                ++it;
        }
    }

    void removeDeadFighters()
    {
        for (auto it = fighters.begin(); it != fighters.end();)
        {
            if (!(*it)->isAlive) 
                it = fighters.erase(it);
            else 
                ++it;
        }
    }

    Fighter* pickRandomFighter() 
    {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        static std::uniform_int_distribution<std::size_t> dist(0, fighters.size() - 1);
        size_t random_index = dist(rng);
        return fighters[random_index];
    }
};

struct Arena
{
    array<Fighter*, 2> fighters = {nullptr, nullptr};

    void announce()
    {
        string text = fighters[0]->getPrettyName() + " VS " + fighters[1]->getPrettyName();
        cout << framedText(text) << endl;
    }

    void fight()
    {
        fighters[0]->health -= fighters[1]->damage;
        fighters[1]->health -= fighters[0]->damage;
        fighters[0]->isAlive = fighters[0]->health > 0;
        fighters[1]->isAlive = fighters[1]->health > 0;
    }
};