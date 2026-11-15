#include <stdexcept>
#include "UnitTypeInfo.h"
std::unordered_map<UnitType, std::shared_ptr<UnitTypeInfo>> UnitTypeInfo::pool;

UnitTypeInfo::UnitTypeInfo(int mH, int bA, int bS, int cost, UnitType type, const std::string& typeName)
    : maxHealth(mH),baseAttack(bA), baseSpeed(bS), cost(cost),  type(type), typeName(typeName) {};
std::shared_ptr<UnitTypeInfo> UnitTypeInfo::getInfo(UnitType type) {
    auto it = pool.find(type);
    if (it != pool.end()) {
        return it->second; 
    }

    std::shared_ptr<UnitTypeInfo> newInfo;
    switch (type) {
        case UnitType::Infantry:
            newInfo = std::make_shared<UnitTypeInfo>(100, 15, 2, 50, UnitType::Infantry, "Пехотинец");
            break;
        case UnitType::Archer:
            newInfo = std::make_shared<UnitTypeInfo>(70, 20, 3, 60, UnitType::Archer, "Лучник");
            break;
        case UnitType::Mage:
            newInfo = std::make_shared<UnitTypeInfo>(60, 30, 2, 80, UnitType::Mage, "Маг");
            break;
        case UnitType::FlyingUnit:
            newInfo = std::make_shared<UnitTypeInfo>(80, 18, 5, 90, UnitType::FlyingUnit, "Летающий юнит");
            break;
        default:
            throw std::invalid_argument("Неизвестный тип юнита");
    }

    pool[type] = newInfo;
    return newInfo;
}
int UnitTypeInfo::getMaxHealth() const {
    return maxHealth;
}

int UnitTypeInfo::getBaseAttack() const {
    return baseAttack;
}

int UnitTypeInfo::getBaseSpeed() const {
    return baseSpeed;
}

int UnitTypeInfo::getCost() const {
    return cost;
}

UnitType UnitTypeInfo::getType() const {
    return type;
}

const std::string& UnitTypeInfo::getTypeName() const {
    return typeName;
}