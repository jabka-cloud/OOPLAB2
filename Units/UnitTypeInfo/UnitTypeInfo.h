#pragma once
#include <string>
#include <unordered_map>
#include <memory>

enum class UnitType{
    Infantry,
    Mage,
    Archer,
    FlyingUnit
};
class UnitTypeInfo{
private:
    const int maxHealth;
    const int baseAttack;
    const int baseSpeed;
    const int cost;
    const UnitType type;
    const std::string typeName;
    static std::unordered_map<UnitType, std::shared_ptr<UnitTypeInfo>> pool;

public:
    UnitTypeInfo(int mH, int bA, int bS, int cost, UnitType type, const std::string& typeName);
    ~UnitTypeInfo() = default;
    static std::shared_ptr<UnitTypeInfo> getInfo(UnitType type);
    
    int getMaxHealth() const;
    int getBaseAttack() const;
    int getBaseSpeed() const;
    int getCost() const;
    UnitType getType() const;
    const std::string& getTypeName() const; 
};