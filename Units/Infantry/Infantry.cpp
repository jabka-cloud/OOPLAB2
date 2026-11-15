#include "Infantry.h"
#include <iostream>

Infantry::Infantry(int startX, int startY)
    : Unit(UnitType::Infantry, startX, startY), bonusAttack(0) {}

void Infantry::addAttackBonus(int value) {
    bonusAttack += value;
    std::cout << "[Infantry #" << getId() << "] Бонус атаки увеличен до +" << bonusAttack << "\n";
}

void Infantry::move(const Position& newPos) {
    position = newPos;
    std::cout << "[Infantry #" << getId() << "] Переместился на (" << position.x << ", " << position.y << ")\n";
}

void Infantry::attack(const std::shared_ptr<Unit>& target) {
    if (!target || target->getHealth() <= 0) {
        return;
    }

    int distance = std::max(std::abs(position.x - target->getPosition().x),
                            std::abs(position.y - target->getPosition().y));

    if (distance <= 1) {
        int totalDamage = getTypeInfo()->getBaseAttack() + bonusAttack;
        std::cout << "[Infantry #" << getId() << "] Атакует мечом юнита #" << target->getId()<< " (урон: " << totalDamage << ")\n";
        target->takeDamage(totalDamage);
    } else {
        std::cout << "[Infantry #" << getId() << "] Цель #" << target->getId() << " вне зоны ближнего боя!\n";
    }
}

void Infantry::takeDamage(int amount) {
    if (health <= 0) return;

    health -= amount;
    if (health <= 0) {
        health = 0;
        notify(UnitEvent::Died);
    } else {
        notify(UnitEvent::Damaged);
    }
}

