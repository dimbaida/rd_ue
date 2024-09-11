#include "Building.h"


int Building::NextId = 0;

Building::Building()
{
    ThisId = NextId;
    NextId++;
}

Building::~Building()
{
    NextId--;
}

int Building::Id()
{
    return ThisId;
}
