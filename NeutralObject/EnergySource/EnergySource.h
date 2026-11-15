#pragma once
#include "NeutralObject.h"
class EnergySource : public NeutralObject {
public:
    explicit EnergySource(int manaBonus = 50);
    void interact(Unit& unit) override;
};