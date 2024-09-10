#ifndef BUILDING_H  // Include guard to prevent multiple inclusions
#define BUILDING_H

class Building
{
private:
    int MaxAge;
    int InitialCost;
public:
    int Age;
    Building();
    ~Building();
    int GetCost();
    void ToAge(const int& years);
    void Destroy();
};

#endif