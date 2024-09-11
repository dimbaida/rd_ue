#include <iostream>
#include "Building.h"


int main()
{
    Building B1(80, 2300);
    B1.info();
    std::cin.get();

    Building B2(90, 5300);
    B2.info();
    std::cin.get();
    
    B1.toAge(33);
    B1.info();
    std::cin.get();

    B1.toAge(40);
    B1.info();
    std::cin.get();

}