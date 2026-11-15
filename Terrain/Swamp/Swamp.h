#pragma once
#include "Terrain.h"
class Swamp : public Terrain {
public:
    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    double getDefenseBonus(UnitType type) const override;
};