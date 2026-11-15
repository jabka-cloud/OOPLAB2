#pragma once
#include "IInteractionStrategy.h"
class AttackBoostStrategy : public IInteractionStrategy {
private:
    int bonusAmount;
public:
    explicit AttackBoostStrategy(int bonus = 10);
    ~AttackBoostStrategy() override = default;
    void execute(const std::shared_ptr<Unit>& unit) const override;
};