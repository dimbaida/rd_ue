#include <iostream>


void clearConsole() 
{
    std::cout << "\033[2J\033[H";
}

std::string framedText(const std::string &text)
{
    std::string out = "\u250c\u2500";
    for (int i = 0; i < text.length() - 4; i++)
        out += "\u2500";
    out += "\u2500\u2510\n\u2502 " + text + " \u2502\n\u2514\u2500";
    for (int i = 0; i < text.length() - 4; i++)
        out += "\u2500";
    out += "\u2500\u2518";
    return out;
}
