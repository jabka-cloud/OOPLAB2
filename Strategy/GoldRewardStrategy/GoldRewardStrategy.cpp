#include "GoldRewardStrategy.h"
#include <iostream>

GoldRewardStrategy::GoldRewardStrategy(const std::shared_ptr<Base>& base, int amount)
    : goldAmount(amount), targetBase(base) {}

void GoldRewardStrategy::execute(const std::shared_ptr<Unit>& unit) const {
    if (!unit) return;

    std::cout << "[Strategy] Юнит #" << unit->getId() << " (" << unit->getType()<< ") нашел сокровище на " << goldAmount << " золота!\n";

    if (auto base = targetBase.lock()) {
        base->addGold(goldAmount);
        std::cout << "[Base] Казна базы пополнена! Текущее золото: " << base->getGold() << "\n";
    }
}
