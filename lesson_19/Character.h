#include <memory>
#include <array>
#include "Weapon.h"


class Character
{
public:
    Character(const std::string& _name) : name(_name) {}; 
    ~Character() = default;

    void TakeWeapon(std::unique_ptr<Weapon> weaponPtr, bool report = true)
    {
        for (auto& weaponSlot : inventory)
        {
            if (!weaponSlot)
            {
                weaponSlot = std::move(weaponPtr);
                if (report)
                    std::cout << name << " picked up " << weaponSlot.get()->GetName() << std::endl;
                return;
            }
        }
        std::cout << "Inventory is full! " << weaponPtr.get()->GetName() << " cannot be picked up!" << std::endl;
    }

    Weapon* GetEquippedWeapon() const
    {
        return weaponEquipped.get();
    }

    void EquipFromInventoryByIndex(const int& i)
    {
        if (i < 0 || i >= inventory.size())
            std::cout << "wrong slot number" << std::endl;

        if (!weaponEquipped)
        {
            weaponEquipped = std::move(inventory[i]);
            std::cout << weaponEquipped.get()->GetName() << " was equipped" << std::endl;
        }
        else
        {
            std::unique_ptr<Weapon> weaponUnequipped = std::move(weaponEquipped);
            Weapon* weaponUnequippedPtr = weaponUnequipped.get();
            weaponEquipped = std::move(inventory[i]);
            Weapon* weaponEquippedPtr = weaponEquipped.get();
            TakeWeapon(std::move(weaponUnequipped), false);
            std::cout << name << " switched " << weaponUnequippedPtr->GetName() << " with " << weaponEquippedPtr->GetName() << std::endl;
        }
    }

    std::string GetName() const
    {
        return name;
    }

private:
    std::string name;
    std::array<std::unique_ptr<Weapon>, 3> inventory;
    std::unique_ptr<Weapon> weaponEquipped;
};
