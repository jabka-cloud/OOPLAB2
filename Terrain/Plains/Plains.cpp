#include "Plains.h"
bool Plains::isPassable(UnitType type) const {
    return true;
}
double Plains::getSpeedModifier(UnitType type) const {
    return 1.0;
}
double Plains::getDefenseBonus(UnitType type) const {
    return 0.0;
}