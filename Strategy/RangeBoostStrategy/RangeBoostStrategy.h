#pragma once
#include "IInteractionStrategy.h"
class RangeBoostStrategy : public IInteractionStrategy {
private:
    int rangeBonus;
public:
    explicit RangeBoostStrategy(int bonus = 2);
    ~RangeBoostStrategy() override = default;
    void execute(const std::shared_ptr<Unit>& unit) const override;
};