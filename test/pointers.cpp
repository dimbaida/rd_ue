#include <iostream>
#include <string>
#include <array>


using namespace std;

struct Fighter
{
    string name;
    int health;
    int damage;
};


void usingPointers(Fighter& f1, Fighter& f2)
{
    array<Fighter*, 2> fighters =  {&f1, &f2};;
    // for (auto* fighter : fighters)
    // {
    //     fighter->health -= 1;
    // }
    fighters[0]->health -= fighters[1]->damage;
    fighters[1]->health -= fighters[0]->damage;
}


int main()
{
    Fighter f1;
    f1.name = "Ragnar";
    f1.health = 10;
    f1.damage = 1;

    Fighter f2;
    f2.name = "Bjorn";
    f2.health = 10;
    f2.damage = 2;

    usingPointers(f1, f2);

    cout << f1.name << '(' << f1.damage << '/' << f1.health << ')' << endl;
    cout << f2.name << '(' << f2.damage << '/' << f2.health << ')' << endl;

    return 0;
}