#pragma once
#include "Unit.h"
class Archer : public Unit{
public:
    std::string getType() const override;
};