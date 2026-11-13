#pragma once
#include "NeutralObject.h"
class EnergySource : public NeutralObject {
    void interact(Unit& u) override;
};