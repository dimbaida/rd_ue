#include <cmath>
#include "Building.h"


Building::Building()
{
}

Building::~Building()
{
}

int Building::GetCost()
{
    float Age =  InitialCost * (1 - (float)Age / (float)MaxAge);
    return (int)Age;
}

void Building::ToAge(const int &years)
{
    
}

void Building::Destroy()
{
}
