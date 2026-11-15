#pragma once
#include "NeutralObject.h"
#include "Base.h"
class TreasureChest : public NeutralObject {
public:
    TreasureChest(const std::shared_ptr<Base>& base, int goldAmount = 100);
    void interact(Unit& unit) override;
};