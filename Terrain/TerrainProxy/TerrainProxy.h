#pragma once
#include <memory>
#include <map>
#include "Terrain.h"
class TerrainProxy : public Terrain {
private:
    std::unique_ptr<Terrain> realTerrain;
    mutable std::map<UnitType, bool> passabilityCache;
    bool isOccupied;
public:
    explicit TerrainProxy(std::unique_ptr<Terrain> terrain);
    ~TerrainProxy() override = default;

    void setOccupied(bool occupied);
    bool getOccupied() const;

    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    double getDefenseBonus(UnitType type) const override;
};