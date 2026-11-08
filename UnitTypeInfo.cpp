#include "UnitTypeInfo.h"
UnitTypeInfo::UnitTypeInfo(int mH, int bA, int bS, int cost, UnitType type, const std::string& typeName)
    : maxHealth(mH),baseAttack(bA), baseSpeed(bS), cost(cost),  type(type), typeName(typeName) {};

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