#include "Altar.h"
#include "AttackBoostStrategy.h"
#include "RangeBoostStrategy.h"
#include "ManaRestoreStrategy.h"

Altar::Altar() {
    strategies[UnitType::Infantry] = std::make_shared<AttackBoostStrategy>(10);
    strategies[UnitType::Archer]   = std::make_shared<RangeBoostStrategy>(2);
    strategies[UnitType::Mage]     = std::make_shared<ManaRestoreStrategy>(40);
}

void Altar::interact(Unit& unit) {
    applyStrategy(unit);
}