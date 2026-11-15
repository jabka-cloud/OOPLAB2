#pragma once
#include <memory>
#include "Unit.h"
#include "UnitTypeInfo.h"

class UnitFactory {
public:
    static std::shared_ptr<Unit> createUnit(UnitType type, int x, int y);
};