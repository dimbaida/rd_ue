#include <iostream>
#include "Building.h"

using namespace std;

int main()
{
    Building Building_01;
    Building Building_02;
    Building Building_03;
    Building Building_04;

    cout << "building_1 id: " << Building_01.Id() << endl;
    cout << "building_2 id: " << Building_02.Id() << endl;
    cout << "building_3 id: " << Building_03.Id() << endl;
    cout << "building_4 id: " << Building_04.Id() << endl;

}