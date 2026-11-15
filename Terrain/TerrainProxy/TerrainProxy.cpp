#include "TerrainProxy.h"
#include <stdexcept>
#include <iostream>
TerrainProxy::TerrainProxy(std::unique_ptr<Terrain> terrain) : realTerrain(std::move(terrain)), isOccupied(false) {
    if (!realTerrain) {
        throw std::invalid_argument("TerrainProxy не может оборачивать пустой указатель!");
    }
}
void TerrainProxy::setOccupied(bool occupied){
    isOccupied = occupied;
}
bool TerrainProxy::getOccupied() const{
    return isOccupied;
}

bool TerrainProxy::isPassable(UnitType type) const{
    if (isOccupied) {
        std::cout << "[TerrainProxy] Клетка занята! Проход закрыт.\n";
        return false;
    }

    auto it = passabilityCache.find(type);
    if (it != passabilityCache.end()) {
        std::cout << "[TerrainProxy] Результат проходимости взят из кэша.\n";
        return it->second;
    }

    bool result = realTerrain->isPassable(type);
    passabilityCache[type] = result;
    std::cout << "[TerrainProxy] Вычислена и закэширована проходимость реального ландшафта.\n";
    
    return result;
}

double TerrainProxy::getSpeedModifier(UnitType type) const{
    return realTerrain->getSpeedModifier(type);
}
double TerrainProxy::getDefenseBonus(UnitType type) const{
    return realTerrain->getDefenseBonus(type);  
}