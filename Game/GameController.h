#pragma once

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include "TerrainMap.h"
#include "Base.h"
#include "NeutralObject.h"
#include "TreasureChest.h"
#include "Trap.h"
#include "Altar.h"
#include "EnergySource.h"

struct MapObject {
    Position pos;
    std::shared_ptr<NeutralObject> obj;
};

class GameController {
private:
    std::unique_ptr<TerrainMap> map;
    std::shared_ptr<Base> base;
    std::vector<MapObject> neutralObjects;
    std::ofstream logFile;

    void log(const std::string& message);

public:
    GameController(int mapWidth, int mapHeight);
    ~GameController();

    void setupWorld();

    bool moveUnit(const std::shared_ptr<Unit>& unit, const Position& targetPos);

    void runScenario1_Creation();
    void runScenario2_MovementAndProxy();
    void runScenario3_NeutralObjectsAndOperators();
    void runScenario4_CombatAndObserver();

    void run();
};
