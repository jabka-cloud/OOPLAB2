#pragma once
#include "NeutralObject.h"
class Altar : public NeutralObject {
public:
    Altar();
    void interact(Unit& unit) override;
};