#include "FlyingUnit.h"
#include <iostream>

FlyingUnit::FlyingUnit(int startX, int startY)
    : Unit(UnitType::FlyingUnit, startX, startY) {}

void FlyingUnit::move(const Position& newPos) {
    position = newPos;
    std::cout << "[FlyingUnit #" << getId() << "] Перелетел на (" << position.x << ", " << position.y << ")\n";
}

void FlyingUnit::attack(const std::shared_ptr<Unit>& target) {
    if (!target || target->getHealth() <= 0) {
        return;
    }

    int distance = std::max(std::abs(position.x - target->getPosition().x),
                            std::abs(position.y - target->getPosition().y));

    if (distance <= 2) {
        int damage = getTypeInfo()->getBaseAttack();
        std::cout << "[FlyingUnit #" << getId() << "] Пикирует с воздуха на юнита #" << target->getId() << " (урон: " << damage << ")\n";
        target->takeDamage(damage);
    } else {
        std::cout << "[FlyingUnit #" << getId() << "] Цель #" << target->getId() << " вне зоны пикирования!\n";
    }
}

void FlyingUnit::takeDamage(int amount) {
    if (health <= 0) return;

    int reducedDamage = std::max(1, static_cast<int>(amount * 0.8));
    health -= reducedDamage;

    if (health <= 0) {
        health = 0;
        notify(UnitEvent::Died);
    } else {
        notify(UnitEvent::Damaged);
    }
}

