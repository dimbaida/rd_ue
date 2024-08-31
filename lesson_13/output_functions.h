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

void outputTurnNumber(const int &turn)
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