#ifndef BOW_H  // Include guard to prevent multiple inclusions
#define BOW_H

#include <string>
#include "Weapon.h"

class Bow : public Weapon
{
public:
    Bow(const std::string& _name, const float& _damage, const int& _arrows) : name(_name), damage(_damage), arrows(_arrows) {}; 
    virtual std::string GetName()
    {
        return name;
    }
    virtual float GetDamage()
    {
        return damage;
    }
    void AddArrows(const int& amt)
    {
        arrows += amt;
    }
    void SpendArrow()
    {
        arrows--;
    }
private:
    std::string name;
    float damage;
    int arrows;
};

#endif