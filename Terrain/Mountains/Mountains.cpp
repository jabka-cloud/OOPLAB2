#include "Mountains.h"
bool Mountains::isPassable(UnitType type) const {
    switch (type){
        case UnitType::FlyingUnit: 
            return true;
        default:
            return false;
    }
}
double Mountains::getSpeedModifier(UnitType type) const {
    switch (type){
        case UnitType::FlyingUnit: 
            return 2.0;
        
        default:
            return 0.5;
    }
}
double Mountains::getDefenseBonus(UnitType type) const {
    switch (type){
        case UnitType::FlyingUnit: 
            return 0.5;
        
        default:
            return 0.0;
    }
}