#pragma once
#include "Unit.h"
class FlyingUnit : public Unit { 
public:
    FlyingUnit(int startX, int startY);
    void move(const Position& newPos) override;
    void attack(const std::shared_ptr<Unit>& target) override;
    void takeDamage(int amount) override;
};