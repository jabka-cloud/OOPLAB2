#pragma once
#include "NeutralObject.h"
class Altar : NeutralObject {
    void interact(Unit& u) override;
};