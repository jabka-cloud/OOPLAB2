#pragma once
#include <memory>
#include <vector>
#include "Unit.h"
#include "IObserver.h"
class Base : public IObserver{
private:
    int health;
    const int maxUnits = 67;
    int defenseLevel;
    int gold;
    std::vector<std::shared_ptr<Unit>> activeUnit;
public:
    void onBaseStatusChanged() override;

    std::shared_ptr<Unit> createUnit(UnitType type, int x, int y);
    void handleUnitDeath(std::shared_ptr<Unit> unit);

    int getGold() const;
    int getHealth() const;
    const std::vector<std::shared_ptr<Unit>>& getActiveUnits() const;
};