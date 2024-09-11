#ifndef BUILDING_H  // Include guard to prevent multiple inclusions
#define BUILDING_H


class Building
{
public:
    Building();
    Building(const int& _MaxAge, const int& _InitialCost);
    ~Building();
    int getId();
    int getAge();
    int getCost();
    void toAge(const int& years);
    void info();
private:
    static int NextId;
    int ThisId = -1;
    int Age = 0;
    int MaxAge = 100;
    int InitialCost = 1e6;
    void destroy();
};

#endif