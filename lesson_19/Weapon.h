#ifndef WEAPON_H  // Include guard to prevent multiple inclusions
#define WEAPON_H

#include <string>

class Weapon
{
public:
    Weapon() = default;
    virtual ~Weapon() = default;
    virtual float GetDamage() = 0;
    virtual std::string GetName() = 0;
};

#endif