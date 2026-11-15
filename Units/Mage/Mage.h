#pragma once
#include "Unit.h"
class Mage : public Unit{
private:
    int mana;
public:
    Mage(int startX, int startY);
    void restoreMana(int value);
    void move(const Position& newPos) override;
    void attack(const std::shared_ptr<Unit>& target) override;
    void takeDamage(int amount) override;
};