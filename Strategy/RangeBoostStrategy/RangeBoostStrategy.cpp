#include "RangeBoostStrategy.h"
#include "Archer.h"
#include <iostream>
RangeBoostStrategy::RangeBoostStrategy(int amount):rangeBonus(amount){}
void RangeBoostStrategy::execute(const std::shared_ptr<Unit>& unit) const{
    if (!unit) return;

    auto archer = std::dynamic_pointer_cast<Archer>(unit);
    if (archer) {
        std::cout << "[Strategy] Применено увеличение дальности (+" << rangeBonus << ") к лучнику #" << archer->getId() << "\n";
        archer->increaseRange(rangeBonus);
    } else {
        std::cout << "[Strategy] RangeBoostStrategy действует только на лучников!\n";
    }
}