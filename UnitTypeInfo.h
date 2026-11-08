#pragma once
#include <string>
enum class UnitType{
    Infantry,
    Mage,
    Archer,
    FlyingUnit
};
class UnitTypeInfo{
private:
    int maxHealth;
    int baseAttack;
    int baseSpeed;
    int cost;
    UnitType type;
    std::string typeName;
public:
    UnitTypeInfo(int mH, int bA, int bS, int cost, UnitType type, const std::string& typeName);
    ~UnitTypeInfo() = default;
    int getMaxHealth() const;
    int getBaseAttack() const;
    int getBaseSpeed() const;
    int getCost() const;
    UnitType getType() const;
    const std::string& getTypeName() const; 
};