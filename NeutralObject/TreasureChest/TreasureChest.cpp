#include "TreasureChest.h"
#include "GoldRewardStrategy.h"
#include <iostream>

TreasureChest::TreasureChest(const std::shared_ptr<Base>& base, int goldAmount) {
    auto goldStrategy = std::make_shared<GoldRewardStrategy>(base, goldAmount);
    strategies[UnitType::Infantry]   = goldStrategy;
    strategies[UnitType::Archer]     = goldStrategy;
    strategies[UnitType::Mage]       = goldStrategy;
    strategies[UnitType::FlyingUnit] = goldStrategy;
}

void TreasureChest::interact(Unit& unit) {
    if (isUsed) {
        std::cout << "[TreasureChest] Сундук уже пуст!\n";
        return;
    }
    applyStrategy(unit);
    isUsed = true;
}