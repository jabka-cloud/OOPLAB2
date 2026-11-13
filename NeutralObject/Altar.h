#pragma once
#include "NeutralObject.h"
class Altar : public NeutralObject {
    void interact(Unit& u) override;
};