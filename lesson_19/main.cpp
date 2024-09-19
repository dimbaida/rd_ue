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

    Character hero("Siegfried");
    std::cout << hero.GetName() << " arrived!" << std::endl;
    std::cin.get();

    std::unique_ptr<Weapon> swordPtr = std::make_unique<Sword>("Dawnbreaker", 100.0f);
    std::unique_ptr<Weapon> bowPtr = std::make_unique<Bow>("Sylphstrike", 50.0f, 10);
    std::unique_ptr<Weapon> daggerPtr = std::make_unique<Dagger>("Nightshade", 20.0f);
    std::unique_ptr<Weapon> shittyDaggerPtr = std::make_unique<Dagger>("Rustbite", 0.2f);

    hero.TakeWeapon(std::move(swordPtr));
    std::cin.get();
    hero.TakeWeapon(std::move(bowPtr)); 
    std::cin.get();
    hero.TakeWeapon(std::move(daggerPtr)); 
    std::cin.get();
    hero.TakeWeapon(std::move(shittyDaggerPtr));  // no inventory capacity
    std::cin.get();

    hero.EquipFromInventoryByIndex(0);
    std::cin.get();

    std::cout << hero.GetName() << " holds " << hero.GetEquippedWeapon()->GetName() << std::endl;
    std::cin.get();

    hero.EquipFromInventoryByIndex(1);
    std::cin.get();

    std::cout << hero.GetName() << " holds " << hero.GetEquippedWeapon()->GetName() << std::endl;
    std::cin.get();

    return 0;
}