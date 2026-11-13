#pragma once
#include "Unit.h"
class Mage : public Unit{
public:
    std::string getType() const override;
};