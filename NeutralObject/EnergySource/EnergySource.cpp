#include "EnergySource.h"
#include "ManaRestoreStrategy.h"

EnergySource::EnergySource(int manaBonus) {
    auto manaStrategy = std::make_shared<ManaRestoreStrategy>(manaBonus);
    strategies[UnitType::Mage] = manaStrategy;
}

void EnergySource::interact(Unit& unit) {
    applyStrategy(unit);
}