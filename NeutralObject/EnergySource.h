#pragma once
#include "NeutralObject.h"
class EnergySource : NeutralObject {
    void interact(Unit& u) override;
};