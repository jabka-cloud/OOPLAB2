#pragma once
#include "Terrain.h"
class Mountains : Terrain {
public:
    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    double getDefenseBonus(UnitType type) const override;
};