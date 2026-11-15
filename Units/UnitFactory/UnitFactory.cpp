#include "UnitFactory.h"
#include "Infantry.h"
#include "Archer.h"
#include "Mage.h"
#include "FlyingUnit.h"
#include <stdexcept>

std::shared_ptr<Unit> UnitFactory::createUnit(UnitType type, int x, int y) {
    switch (type) {
        case UnitType::Infantry:
            return std::make_shared<Infantry>(x, y);
        case UnitType::Archer:
            return std::make_shared<Archer>(x, y);
        case UnitType::Mage:
            return std::make_shared<Mage>(x, y);
        case UnitType::FlyingUnit:
            return std::make_shared<FlyingUnit>(x, y);
        default:
            throw std::invalid_argument("Неизвестный тип юнита для фабрики");
    }
}
