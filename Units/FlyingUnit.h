#pragma once
#include "Unit.h"
class FlyingUnit : public Unit{
public:
    std::string getType() const override;
};