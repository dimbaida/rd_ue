#ifndef DAGGER_H  // Include guard to prevent multiple inclusions
#define DAGGER_H

#include <string>
#include "Weapon.h"

class Dagger : public Weapon
{
public:
    Dagger(const std::string& _name, const float& _damage) : name(_name), damage(_damage) {}; 
    
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