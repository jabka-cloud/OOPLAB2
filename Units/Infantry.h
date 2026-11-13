#pragma once
#include "Unit.h"
class Infantry : public Unit{
public:
    std::string getType() const override;
};