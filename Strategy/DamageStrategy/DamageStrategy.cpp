#include "DamageStrategy.h"
#include <iostream>
DamageStrategy::DamageStrategy(int damage):damageAmount(damage){}
void DamageStrategy::execute(const std::shared_ptr<Unit>& unit) const{
    if (!unit || unit->getHealth() <= 0) return;

    std::cout << "[Strategy] Ловушка сработала! Юнит #" << unit->getId()
              << " (" << unit->getType() << ") получает " << damageAmount << " урона.\n";
    
    unit->takeDamage(damageAmount);
}