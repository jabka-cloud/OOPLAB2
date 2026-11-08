#pragma once
#include "Terrain.h"
class Plains : Terrain {
public:
    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    double getDefenseBonus(UnitType type) const override;
};