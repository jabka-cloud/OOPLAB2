#pragma once
#include "NeutralObject.h"
class Trap : public NeutralObject {
public:
    explicit Trap(int damage = 25);
    void interact(Unit& unit) override;
};