#include "ManaRestoreStrategy.h"
#include "Mage.h"
#include <iostream>
ManaRestoreStrategy::ManaRestoreStrategy(int amount):bonusMana(amount){}
void ManaRestoreStrategy::execute(const std::shared_ptr<Unit>& unit) const{
    if (!unit) return;

    auto mage = std::dynamic_pointer_cast<Mage>(unit);
    if (mage) {
        std::cout << "[Strategy] Применено восстановление маны (+" << bonusMana << ") к магу #" << mage->getId() << "\n";
        mage->restoreMana(bonusMana);
    } else {
        std::cout << "[Strategy] ManaRestoreStrategy действует только на магов!\n";
    }
}