#include "Operators.h"

Unit& operator+(Unit& unit, TreasureChest& chest) {
    chest.interact(unit);
    return unit;
}

Unit& operator-(Unit& unit, Trap& trap) {
    trap.interact(unit);
    return unit;
}

Unit& operator*(Unit& unit, Altar& altar) {
    altar.interact(unit);
    return unit;
}

Unit& operator/(Unit& unit, EnergySource& source) {
    source.interact(unit);
    return unit;
}

std::shared_ptr<Unit> operator+(const std::shared_ptr<Unit>& unit, TreasureChest& chest) {
    if (unit) chest.interact(*unit);
    return unit;
}

std::shared_ptr<Unit> operator-(const std::shared_ptr<Unit>& unit, Trap& trap) {
    if (unit) trap.interact(*unit);
    return unit;
}

std::shared_ptr<Unit> operator*(const std::shared_ptr<Unit>& unit, Altar& altar) {
    if (unit) altar.interact(*unit);
    return unit;
}

std::shared_ptr<Unit> operator/(const std::shared_ptr<Unit>& unit, EnergySource& source) {
    if (unit) source.interact(*unit);
    return unit;
}