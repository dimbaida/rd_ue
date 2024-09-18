#ifndef SWORD_H  // Include guard to prevent multiple inclusions
#define SWORD_H

#include <string>
#include "Weapon.h"

class Sword : public Weapon
{
public:
    Sword(const std::string& _name, const float& _damage) : name(_name), damage(_damage) {}; 
    float GetDamage()
    {
        return damage;
    }

    std::string GetName()
    {
        return name;
    }
private:
    std::string name;
    float damage;
};

#endif