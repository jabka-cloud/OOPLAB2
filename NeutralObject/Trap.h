#pragma once
#include "NeutralObject.h"
class Trap : NeutralObject {
    void interact(Unit& u) override;
};