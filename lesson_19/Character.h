#include <memory>
#include <array>
#include "Weapon.h"


class Character
{
public:
    Character(const std::string& _name) : name(_name) {}; 
    ~Character() = default;

    void PickupWeapon(std::unique_ptr<Weapon> weaponPtr)
    {
        for (auto& weaponSlot : inventory)
        {
            if (!weaponSlot)
            {
                weaponSlot = std::move(weaponPtr);
                std::cout << name << "picked up " << weaponSlot.get()->GetName() << std::endl;
                return;
            }
        }
        std::cout << "Inventory is full! " << weaponPtr.get()->GetName() << " cannot be picked up!";
    }

    void EquipWeapon(std::unique_ptr<Weapon> weaponPtr)
    {
        weaponEquipped = std::move(weaponPtr);
        std::cout << name << " equipped " << weaponEquipped.get()->GetName() << std::endl;
    }

    Weapon* GetEquippedWeapon() const
    {
        return weaponEquipped.get();
    }

    std::unique_ptr<Weapon> GetWeaponFromInventoryByIndex(const int& i)
    {
        if (i < 0 || i >= inventory.size())
        {
            std::cout << "wrong slot number" << std::endl;
            return nullptr;
        }
        return std::move(inventory[i]);
    }

    std::string GetName() const
    {
        return name;
    }

private:
    std::string name;
    std::unique_ptr<Weapon> weaponEquipped;
    std::array<std::unique_ptr<Weapon>, 3> inventory;
};
