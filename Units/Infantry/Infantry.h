#pragma once
#include "Unit.h"
class Infantry : public Unit{
private:
    int bonusAttack;
public:
    Infantry(int startX, int startY);
    void addAttackBonus(int value);
    void move(const Position& newPos) override;
    void attack(const std::shared_ptr<Unit>& target) override;
    void takeDamage(int amount) override;
};