#include <iostream>
#include "Building.h"


int Building::NextId = 0;

Building::Building()
{
    ThisId = NextId;
    NextId++;
    std::cout << "Building#" << ThisId << " created" << std::endl;
}

Building::Building(const int &_MaxAge, const int &_InitialCost)
{
    ThisId = NextId;
    NextId++;
    MaxAge = _MaxAge;
    InitialCost = _InitialCost;
    std::cout << "Building#" << ThisId << " created" << std::endl;
}

Building::~Building()
{
}

int Building::getId()
{
    return ThisId;
}

int Building::getAge()
{
    return Age;
}

int Building::getCost()
{
    float currCost = (float)InitialCost * (1. - (float)Age / (float)MaxAge);
    return int(round(currCost));
}

void Building::toAge(const int& years)
{
    Age += years;
    if (Age >= MaxAge) destroy();
}

void Building::info()
{
        std::cout   << "Building#" 
                    << getId() 
                    << " [age: " 
                    << getAge() 
                    << " | cost: " 
                    << getCost()
                    << "]"
                    << std::endl;
}

void Building::destroy()
{
    std::cout << "Building #" << ThisId << " destroyed" << std::endl;
}
