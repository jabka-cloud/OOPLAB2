#pragma once
#include <memory>
#include <vector>
#include "Unit.h"
#include "IObserver.h"
class Base : public IObserver, public std::enable_shared_from_this<Base> {
private:
    int health;
    const int maxUnits = 67;
    int defenseLevel;
    int gold;
    Position position;
    std::vector<std::shared_ptr<Unit>> activeUnits;
public:
    Base(int startHealth, int startGold, int startDefense, int startX, int startY);
    ~Base() override = default;
    void onUnitEvent(const std::shared_ptr<Unit>& unit, UnitEvent event) override;

    std::shared_ptr<Unit> createUnit(UnitType type, int x, int y);
    void handleUnitDeath(const std::shared_ptr<Unit>& unit);
    void removeUnit(const std::shared_ptr<Unit>& unit);

    void addGold(int amount);


    int getGold() const;
    int getHealth() const;
    int getDefenseLevel() const;
    const Position& getPosition() const;
    const std::vector<std::shared_ptr<Unit>>& getActiveUnits() const;
};