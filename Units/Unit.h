#pragma once
#include "UnitTypeInfo.h"
class Unit{
private:
    UnitTypeInfo info;
    int currentHealth;
    int x,y;
public:
    Unit(const UnitTypeInfo* info, int startX, int startY);
    virtual ~Unit() = default;

    virtual std::string getType() const = 0;
    int getX() const { return x; }
    int getY() const { return y; }
    void setCoordinates(int newX, int newY) { x = newX; y = newY; }

    void move(int dx, int dy);
    void takeDamage(int damage);

};