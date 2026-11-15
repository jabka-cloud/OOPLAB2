#pragma once
#include <memory>
#include "Unit.h"
class IInteractionStrategy {
public:
    virtual void execute(const std::shared_ptr<Unit>& unit) const = 0;
    virtual ~IInteractionStrategy() = default;
};