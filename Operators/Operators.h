#pragma once

#include <memory>
#include "Unit.h"
#include "TreasureChest.h"
#include "Trap.h"
#include "Altar.h"
#include "EnergySource.h"

Unit& operator+(Unit& unit, TreasureChest& chest);
Unit& operator-(Unit& unit, Trap& trap);
Unit& operator*(Unit& unit, Altar& altar);
Unit& operator/(Unit& unit, EnergySource& source);

std::shared_ptr<Unit> operator+(const std::shared_ptr<Unit>& unit, TreasureChest& chest);
std::shared_ptr<Unit> operator-(const std::shared_ptr<Unit>& unit, Trap& trap);
std::shared_ptr<Unit> operator*(const std::shared_ptr<Unit>& unit, Altar& altar);
std::shared_ptr<Unit> operator/(const std::shared_ptr<Unit>& unit, EnergySource& source);
