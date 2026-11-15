#include "NeutralObject.h"
#include <iostream>

void NeutralObject::setStrategy(UnitType type, std::shared_ptr<IInteractionStrategy> strategy) {
    strategies[type] = std::move(strategy);
}

void NeutralObject::applyStrategy(Unit& unit) {
    UnitType type = unit.getTypeInfo()->getType();
    auto it = strategies.find(type);

    if (it != strategies.end() && it->second) {
        it->second->execute(unit.shared_from_this());
    } else {
        std::cout << "[NeutralObject] Объект не оказывает эффекта на данный тип юнита.\n";
    }
}
