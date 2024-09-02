#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>


enum Color {
    red,
    green,
    yellow
};

std::string roundedFloatToString(const float &number, const int precision = 2)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(precision) << number;
    return stream.str();
}

std::string framedText(const std::string &text)
{
    std::string out = "\u250c\u2500";
    for (int i = 0; i < text.length(); i++)
        out += "\u2500";
    out += "\u2500\u2510\n\u2502 " + text + " \u2502\n\u2514\u2500";
    for (int i = 0; i < text.length(); i++)
        out += "\u2500";
    out += "\u2500\u2518";
    return out;
}

void outputColoredText(const std::string &text, const Color &color)
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

void outputPrettyHealth(const float &health)
{
    std::string health_text = roundedFloatToString(health);
    health_text = framedText(health_text);
    outputColoredText(health_text, Color::green);
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