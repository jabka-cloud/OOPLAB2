#pragma once
#include <memory>
#include "IInteractionStrategy.h"
#include "Base.h"

class GoldRewardStrategy : public IInteractionStrategy {
private:
    int goldAmount;
    std::weak_ptr<Base> targetBase;

public:
    GoldRewardStrategy(const std::shared_ptr<Base>& base, int amount = 100);
    ~GoldRewardStrategy() override = default;

    void execute(const std::shared_ptr<Unit>& unit) const override;
};