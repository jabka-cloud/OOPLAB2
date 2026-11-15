#pragma once
#include <map>
#include <memory>
#include "Unit.h"
#include "IInteractionStrategy.h"
class NeutralObject {
protected:
    std::map<UnitType, std::shared_ptr<IInteractionStrategy>> strategies;
    bool isUsed = false;
     void applyStrategy(Unit& unit);
public:
    virtual ~NeutralObject() = default;
    void setStrategy(UnitType type, std::shared_ptr<IInteractionStrategy> strategy);
    virtual void interact(Unit& unit) = 0;
};