#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>


enum Color {
    red,
    green,
    yellow
};

std::string roundedFloatToString(const float &number, int precision = 2)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}

void printColored(const std::string &text, const Color &color)
{
    switch (color)
    {
        case red:
            std::cout << "\033[31m"; 
            break;
        case green:
            std::cout << "\033[32m";
            break;
        case yellow:
            std::cout << "\033[33m";
            break;
        default:
            break;
    }
    std::cout << text << "\033[0m" << std::endl; 
}

void outputPrettyHealth(float health)
{
    std::string health_text = roundedFloatToString(health, 2);
    std::string text = "\u250c\u2500";
    for (int i = 0; i < health_text.length() + 8; i++)
        text += "\u2500";

    text = text + "\u2500\u2510\n"
                + "\u2502" + " HEALTH: " + health_text + " \u2502\n"
                + "\u2514\u2500";

    for (int i = 0; i < health_text.length() + 8; i++)
        text += "\u2500";
    text += "\u2500\u2518";
    printColored(text, Color::green);
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