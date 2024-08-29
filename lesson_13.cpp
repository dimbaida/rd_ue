#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

void outputFramedHealth(float health)
{
    health = std::round(health * 100.0) / 100.0;

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << health;
    std::string health_text = stream.str();

    std::string text = "\u250c\u2500";
    for (int i = 0; i < health_text.length() + 8; i++)
        text += "\u2500";

    text = text + "\u2500\u2510\n"
                + "\u2502" + " HEALTH: " + health_text + " \u2502\n"
                + "\u2514\u2500";

    for (int i = 0; i < health_text.length() + 8; i++)
        text += "\u2500";
    text += "\u2500\u2518";
    std::cout << "\033[32m" << text << "\033[0m" << std::endl; 
}

void outputTurnNumber(int turn)
{
    std::cout << "\n===== " << "TURN " << turn << " =====\n";
}

void outputDeathMessage()
{
    std::cout   << "\033[31m"
                << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D\n"
                << "\u271D  You died!  \u271D\n"
                << "\u271D \u271D \u271D \u271D \u271D \u271D \u271D \u271D" << std::endl;
}

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
        if (item_distance > 100.f || std::abs(result_impact) < 1e-3)
            std::cout << "\033[33mItem has no effect";
        else if (item_impact < 0.f)
            std::cout << "\033[31mDamage taken: " << std::abs(result_impact);
        else
            std::cout << "\033[32mHealed: " << std::abs(result_impact);
        std::cout << "\033[0m" << std::endl; 
        
        health += result_impact;

        if (health > 0.f && health < 1.f) 
            health = 1.f;

        outputFramedHealth(health);

        turn++;
    }

    outputDeathMessage();
    return 0;
}