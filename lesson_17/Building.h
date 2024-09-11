#ifndef BUILDING_H  // Include guard to prevent multiple inclusions
#define BUILDING_H


class Building
{
public:
    Building();
    ~Building();
    int Id();
private:
    static int NextId;
    int ThisId = -1;
    int MaxAge;
    int InitialCost;
};

#endif