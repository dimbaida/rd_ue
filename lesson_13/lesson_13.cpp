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
        result_impact = std::abs(result_impact) < 1e-3 ? 0.f : result_impact;
        if (result_impact == 0.f)
            outputColoredText("Item has no effect", Color::yellow);
        else if (item_impact < 0.f)
            outputColoredText("Damage taken: " + roundedFloatToString(abs(result_impact)), Color::red);
        else
            outputColoredText("Healed: " + roundedFloatToString(std::abs(result_impact)), Color::green);
        
        health += result_impact;
        health = (health > 0.f && health < 1.f) ? 1.f : health;

        outputPrettyHealth(health);

        turn++;
    }

    outputDeathMessage();
    return 0;
}