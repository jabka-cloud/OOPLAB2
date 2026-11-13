#pragma once
#include "NeutralObject.h"
class TreasureChest : public NeutralObject {
    void interact(Unit& u) override;
};