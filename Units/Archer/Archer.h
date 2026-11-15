#pragma once
#include "Unit.h"
class Archer : public Unit{
private:
    int attackRange;
public:
    Archer(int startX, int startY);
    void increaseRange(int value);
    void move(const Position& newPos) override;
    void attack(const std::shared_ptr<Unit>& target) override;
    void takeDamage(int amount) override;
};