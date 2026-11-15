#include "Mage.h"
#include <iostream>

Mage::Mage(int startX, int startY)
    : Unit(UnitType::Mage, startX, startY), mana(100) {}

void Mage::restoreMana(int value) {
    mana += value;
    std::cout << "[Mage #" << getId() << "] Мана восстановлена. Текущая мана: " << mana << "\n";
}

void Mage::move(const Position& newPos) {
    position = newPos;
    std::cout << "[Mage #" << getId() << "] Переместился на (" << position.x << ", " << position.y << ")\n";
}

void Mage::attack(const std::shared_ptr<Unit>& target) {
    if (!target || target->getHealth() <= 0) {
        return;
    }

    const int spellCost = 20;
    const int castRange = 4;

    if (mana < spellCost) {
        std::cout << "[Mage #" << getId() << "] Недостаточно маны для заклинания!\n";
        return;
    }

    int distance = std::max(std::abs(position.x - target->getPosition().x),
                            std::abs(position.y - target->getPosition().y));

    if (distance <= castRange) {
        mana -= spellCost;
        int damage = getTypeInfo()->getBaseAttack();
        std::cout << "[Mage #" << getId() << "] Кастует огненный шар в юнита #" << target->getId()
                  << " (урон: " << damage << ", осталось маны: " << mana << ")\n";
        target->takeDamage(damage);
    } else {
        std::cout << "[Mage #" << getId() << "] Цель #" << target->getId() << " слишком далеко для заклинания!\n";
    }
}

void Mage::takeDamage(int amount) {
    if (health <= 0) return;

    health -= amount;
    if (health <= 0) {
        health = 0;
        notify(UnitEvent::Died);
    } else {
        notify(UnitEvent::Damaged);
    }
}

