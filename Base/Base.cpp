#include "Base.h"
#include "UnitFactory.h"
#include <algorithm>
#include <iostream>
Base::Base(int startHealth, int startGold, int startDefense, int startX, int startY):
    health(startHealth),
    gold(startGold),
    defenseLevel(startDefense),
    position(startX , startY ){}
std::shared_ptr<Unit> Base::createUnit(UnitType type, int x, int y){
    if (activeUnits.size() >= static_cast<size_t>(maxUnits)) {
        std::cout << "[Base] Достигнут лимит юнитов!\n";
        return nullptr;
    }   
    auto info = UnitTypeInfo::getInfo(type);
    if (gold < info->getCost()) {
        std::cout << "[Base] Недостаточно золота (gold) для создания юнита!\n";
        return nullptr;
    }
    gold -= info->getCost();
    std::shared_ptr<Unit> newUnit = UnitFactory::createUnit(type, x, y);
    newUnit->subscribe(shared_from_this());
    activeUnits.push_back(newUnit);

    return newUnit;
}

void Base::handleUnitDeath(const std::shared_ptr<Unit>& unit) {
    auto it = std::remove(activeUnits.begin(), activeUnits.end(), unit);
    if (it != activeUnits.end()) {
        activeUnits.erase(it, activeUnits.end());
        std::cout << "[Base] Юнит #" << unit->getId() << " погиб и удален из учета базы.\n";
    }
}

void Base::removeUnit(const std::shared_ptr<Unit>& unit) {
    auto it = std::remove(activeUnits.begin(), activeUnits.end(), unit);
    if (it != activeUnits.end()) {
        activeUnits.erase(it, activeUnits.end());
        std::cout << "[Base] Юнит #" << unit->getId() << " удален из состава базы.\n";
    }
}
void Base::onUnitEvent(const std::shared_ptr<Unit>& unit, UnitEvent event) {
    switch (event) {
        case UnitEvent::Created:
            std::cout << "[Base] Новый юнит #" << unit->getId()  << " (" << unit->getTypeInfo()->getTypeName() << ") готов к бою!\n";
            break;

        case UnitEvent::Damaged:
            std::cout << "[Base] Юнит #" << unit->getId() << " получил урон! Осталось HP: " << unit->getHealth() << "\n";
            break;

        case UnitEvent::Healed:
            std::cout << "[Base] Юнит #" << unit->getId()  << " восстановил здоровье! Текущее HP: " << unit->getHealth() << "\n";
            break;

        case UnitEvent::Died:
            handleUnitDeath(unit);
            break;
    }
}
const std::vector<std::shared_ptr<Unit>>& Base::getActiveUnits() const {
    return activeUnits;
}
void Base::addGold(int amount){
    gold += amount; 
}

int Base::getGold() const{
    return gold;
}

int Base::getHealth() const{
    return health;
}

int Base::getDefenseLevel() const{
    return defenseLevel;
}

const Position& Base::getPosition() const{
    return position;
}