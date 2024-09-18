#include <iostream>
#include <memory>
#include "Character.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"


int main()
{
    std::cout << "\033[2J\033[H";

    Character hero("Aethorion");
    std::cout << hero.GetName() << " arrived!";
    std::cin.get();

    std::unique_ptr<Weapon> sword = std::make_unique<Sword>("Dawnbreaker", 100.0f);
    std::unique_ptr<Weapon> bow = std::make_unique<Bow>("Sylphstrike", 50.0f, 10);
    std::unique_ptr<Weapon> dagger = std::make_unique<Dagger>("Nightshade", 20.0f);
    std::unique_ptr<Weapon> shittyDagger = std::make_unique<Dagger>("Rustbite", 0.2f);

    hero.PickupWeapon(std::move(sword)); 
    std::cin.get();
    hero.PickupWeapon(std::move(bow)); 
    std::cin.get();
    hero.PickupWeapon(std::move(dagger)); 
    std::cin.get();
    hero.PickupWeapon(std::move(shittyDagger));  // no inventory capacity
    std::cin.get();

    std::unique_ptr<Weapon> chosenWeapon = hero.GetWeaponFromInventoryByIndex(0);
    hero.EquipWeapon(std::move(chosenWeapon));
    std::cin.get();

    std::cout << hero.GetName() << " holds " << hero.GetEquippedWeapon()->GetName();
    std::cin.get();

    return 0;
}