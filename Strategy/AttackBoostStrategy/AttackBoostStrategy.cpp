#include "AttackBoostStrategy.h"
#include "Infantry.h"
#include <iostream>
AttackBoostStrategy::AttackBoostStrategy(int bonus):bonusAmount(bonus){}
void AttackBoostStrategy::execute(const std::shared_ptr<Unit>& unit) const{
    if (!unit) return;

    auto infantry = std::dynamic_pointer_cast<Infantry>(unit);
    if (infantry) {
        std::cout << "[Strategy] Применено усиление атаки (+" << bonusAmount << ") к пехотинцу #" 
                  << infantry->getId() << "\n";
        infantry->addAttackBonus(bonusAmount);
    } else {
        std::cout << "[Strategy] AttackBoostStrategy действует только на пехоту!\n";
    }
}