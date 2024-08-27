#include <iostream>

int main()
{
    float health;
    int turn;

    std::cout << "Health: ";
    std::cin >> health;

    while (health > 0.0f)
    {
        std::cout << "\n------\n";
        std::cout << "TURN " << turn;
        std::cout << "\n------\n";

        float item_distance, item_impact;
        std::cout << "Item distance: ";
        std::cin >> item_distance;
        std::cout << "Item impact: "; 
        std::cin >> item_impact;

        float result_impact = item_impact * (1.f - std::min(1.f, item_distance / 100.f));
        if (item_impact <= 0.f)
            std::cout << "Damage taken: " << std::abs(result_impact) << '\n';
        else
            std::cout << "Healed: " << std::abs(result_impact) << '\n';
        
        health += result_impact;

        if (health > 0.0f && health < 1.0f) 
            health = 1.0f;

        std::cout << "Health: " << health << std::endl;

        turn++;
    }
    std::cout << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D" << std::endl;
    std::cout << "\u271D  You died!  \u271D" << std::endl;
    std::cout << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D" << std::endl;
    return 0;
}