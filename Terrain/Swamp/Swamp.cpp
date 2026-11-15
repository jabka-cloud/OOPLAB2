#include "Swamp.h"
bool Swamp::isPassable(UnitType type) const {
    return true;
}
double Swamp::getSpeedModifier(UnitType type) const {
    switch (type){
        case UnitType::FlyingUnit: 
            return 2.0;

        case UnitType::Infantry: 
            return 0.5;

        default:
            return 1.0;
    }
}
double Swamp::getDefenseBonus(UnitType type) const {
    switch (type){

        case UnitType::FlyingUnit: 
            return 0.5;

        case UnitType::Infantry: 
            return -0.5;

        default:
            return 0.0;
    }
}