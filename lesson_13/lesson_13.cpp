#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "output_functions.h"


int main()
{
    float health;
    int turn = 1;

    std::cout << "Health: ";
    std::cin >> health;

    while (health > 0.f && turn < 100)
    {
        outputTurnNumber(turn);

        float item_distance, item_impact;
        std::cout << "Item distance: ";
        std::cin >> item_distance;
        std::cout << "Item impact: "; 
        std::cin >> item_impact;

        float result_impact = item_impact * (1.f - std::min(1.f, std::abs(item_distance) / 100.f));
        if (item_distance > 100.f || std::abs(result_impact) < 1e-6)
            std::cout << "\033[33mItem has no effect";
        else if (item_impact < 0.f)
            std::cout << "\033[31mDamage taken: " << std::abs(result_impact);
        else
            std::cout << "\033[32mHealed: " << std::abs(result_impact);
        std::cout << "\033[0m" << std::endl; 
        
        health += result_impact;
        health = (health > 0.f && health < 1.f) ? 1.f : health;

        outputFramedHealth(health);

        turn++;
    }

    outputDeathMessage();
    return 0;
}