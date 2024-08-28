#include <iostream>

int main()
{
    float health;
    int turn = 1;

    std::cout << "Health: ";
    std::cin >> health;

    while (health > 0.0f || turn > 99)
    {
        std::cout   << "\u250c\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n"
                    << "\u2502" << " TURN " << turn << "  \u2502\n"
                    << "\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n";

        float item_distance, item_impact;
        std::cout << "Item distance: ";
        std::cin >> item_distance;
        std::cout << "Item impact: "; 
        std::cin >> item_impact;

        float result_impact = item_impact * (1.f - std::min(1.f, std::abs(item_distance) / 100.f));
        std::cout   << (item_impact <= 0.f 
                        ? "\033[31mDamage taken: "  // Red color for damage
                        : "\033[32mHealed: ")       // Green color for healing
                    << std::abs(result_impact) 
                    << "\033[0m" << std::endl;      // Reset to default color
        
        health += result_impact;

        if (health > 0.0f && health < 1.0f) 
            health = 1.0f;

        std::cout << "Health: " << health << std::endl;

        turn++;
    }

    std::cout   << "\033[31m"
                << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D\n"
                << "\u271D  You died!  \u271D\n"
                << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D" << std::endl;

    return 0;
}