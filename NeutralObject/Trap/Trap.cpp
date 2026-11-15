#include "Trap.h"
#include "DamageStrategy.h"
#include <iostream>

Trap::Trap(int damage) {
    auto dmgStrategy = std::make_shared<DamageStrategy>(damage);
    strategies[UnitType::Infantry] = dmgStrategy;
    strategies[UnitType::Archer]   = dmgStrategy;
    strategies[UnitType::Mage]     = dmgStrategy;
}

void Trap::interact(Unit& unit) {
    if (isUsed) {
        std::cout << "[Trap] Ловушка уже разряжена.\n";
        return;
    }
    applyStrategy(unit);
    
    if (unit.getTypeInfo()->getType() != UnitType::FlyingUnit) {
        isUsed = true;
    }
}