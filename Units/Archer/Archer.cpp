#include "Archer.h"
#include <iostream>
Archer::Archer(int startX, int startY): 
    Unit(UnitType::Archer, startX, startY), attackRange(3) {}
void Archer::increaseRange(int value){
     attackRange+=value;
     std::cout << "[Archer #" << getId() << "] Дальность стрельбы увеличена до " << attackRange << "\n";
}
void Archer::move(const Position& newPos){
    position = newPos;
     std::cout << "[Archer #" << getId() << "] Переместился на (" << position.x << ", " << position.y << ")\n";
}
void Archer::attack(const std::shared_ptr<Unit>& target){
     if (!target || target->getHealth() <= 0) {
        return;
    }

    int distance = std::max(std::abs(position.x - target->getPosition().x), std::abs(position.y - target->getPosition().y));

    if (distance <= attackRange) {
        int damage = getTypeInfo()->getBaseAttack();
        std::cout << "[Archer #" << getId() << "] Выстрелил в юнита #" << target->getId()<< " с дистанции " << distance << " (урон: " << damage << ")\n";
        target->takeDamage(damage);
    } else {
        std::cout << "[Archer #" << getId() << "] Цель #" << target->getId() << " слишком далеко (дистанция: " << distance << ", дальность: " << attackRange << ")\n";
    }
}
void Archer::takeDamage(int amount){
    if (health <= 0) return;

    health -= amount;
    if (health <= 0) {
        health = 0;
        notify(UnitEvent::Died);
    } else {
        notify(UnitEvent::Damaged);
    }
}
