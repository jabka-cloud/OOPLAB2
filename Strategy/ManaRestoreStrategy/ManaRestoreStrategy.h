#pragma once
#include "IInteractionStrategy.h"
class ManaRestoreStrategy : public IInteractionStrategy {
private:
    int bonusMana;
public:
    explicit ManaRestoreStrategy(int amount = 50);
    ~ManaRestoreStrategy() override = default;
    void execute(const std::shared_ptr<Unit>& unit) const override;

};