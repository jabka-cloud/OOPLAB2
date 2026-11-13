#pragma once
#include "NeutralObject.h"
class Trap : public NeutralObject {
    void interact(Unit& u) override;
};