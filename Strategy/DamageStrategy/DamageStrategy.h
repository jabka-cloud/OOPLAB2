#pragma once
#include "IInteractionStrategy.h"
class DamageStrategy : public IInteractionStrategy {
private:
    int damageAmount;
public:
    explicit DamageStrategy(int damage = 25);
    ~DamageStrategy() override = default;

    void execute(const std::shared_ptr<Unit>& unit) const override;
};