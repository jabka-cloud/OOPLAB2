#include "Forest.h"
bool Forest::isPassable(UnitType type) const {
    switch (type){
        case UnitType::Infantry: 
            return false;
        default:
            return true;
    }
}
double Forest::getSpeedModifier(UnitType type) const {
    switch (type){

        case UnitType::Archer: 
            return 1.0;

        case UnitType::FlyingUnit: 
            return 1.0;
        
        default:
            return 0.5;
    }
}
double Forest::getDefenseBonus(UnitType type) const {
    return 0.5;
}