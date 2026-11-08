#pragma once
#include "Unit.h"
class NeutralObject{
public:
    ~NeutralObject() = default;
    
    virtual void interact(Unit& u) = 0;
};