#include "GameController.h"
#include "TerrainProxy.h"
#include "Plains.h"
#include "Forest.h"
#include "Swamp.h"
#include "Mountains.h"
#include "Operators.h"
#include <iostream>

GameController::GameController(int mapWidth, int mapHeight) {
    logFile.open("game_log.txt");
    map = std::make_unique<TerrainMap>(mapWidth, mapHeight);
    log("=== Инициализация GameController ===");
}

GameController::~GameController() {
    log("=== Завершение работы симуляции ===");
    if (logFile.is_open()) {
        logFile.close();
    }
}

void GameController::log(const std::string& message) {
    std::cout << message << "\n";
    if (logFile.is_open()) {
        logFile << message << "\n";
    }
}

void GameController::setupWorld() {
    log("\n--- Настройка карты и ландшафта (TerrainProxy) ---");
    map->setTerrain(1, 1, std::make_unique<TerrainProxy>(std::make_unique<Forest>()));
    map->setTerrain(2, 2, std::make_unique<TerrainProxy>(std::make_unique<Swamp>()));
    map->setTerrain(3, 3, std::make_unique<TerrainProxy>(std::make_unique<Mountains>()));
    map->setTerrain(4, 1, std::make_unique<TerrainProxy>(std::make_unique<Plains>()));
    log("Карта размером " + std::to_string(map->getWidth()) + "x" + std::to_string(map->getHeight()) + " сгенерирована.");
}

bool GameController::moveUnit(const std::shared_ptr<Unit>& unit, const Position& targetPos) {
    if (!unit) return false;

    Terrain* cell = map->getTerrain(targetPos);
    if (!cell) {
        log("[Move] Ошибка: выход за границы карты!");
        return false;
    }

    UnitType uType = unit->getTypeInfo()->getType();
    log("[Move] Попытка переместить " + unit->getType() + " #" + std::to_string(unit->getId()) +
        " на (" + std::to_string(targetPos.x) + ", " + std::to_string(targetPos.y) + ")");

    if (cell->isPassable(uType)) {
        double speedMod = cell->getSpeedModifier(uType);
        double defBonus = cell->getDefenseBonus(uType);
        unit->move(targetPos);
        log("[Move] Успех! Модификатор скорости: " + std::to_string(speedMod) +
            ", бонус защиты: " + std::to_string(defBonus));
        return true;
    } else {
        log("[Move] Отказ: ландшафт непроходим для данного типа юнита!");
        return false;
    }
}

void GameController::runScenario1_Creation() {
    log("\n=== СЦЕНАРИЙ 1: Создание базы и юнитов через Фабрику ===");
    base = std::make_shared<Base>(500, 1000, 10, 0, 0);
    log("База создана на (0, 0). Стартовое золото: " + std::to_string(base->getGold()));

    auto u1 = base->createUnit(UnitType::Infantry, 0, 1);
    auto u2 = base->createUnit(UnitType::Archer, 1, 0);
    auto u3 = base->createUnit(UnitType::Mage, 0, 2);
    auto u4 = base->createUnit(UnitType::FlyingUnit, 2, 0);

    log("Всего активных юнитов на базе: " + std::to_string(base->getActiveUnits().size()));
    log("Остаток золота после найма: " + std::to_string(base->getGold()));
}

void GameController::runScenario2_MovementAndProxy() {
    log("\n=== СЦЕНАРИЙ 2: Перемещение по ландшафту с проверкой Proxy ===");
    const auto& units = base->getActiveUnits();
    if (units.size() < 4) return;

    auto infantry = units[0];
    auto flying = units[3];

    moveUnit(infantry, Position(3, 3));

    moveUnit(infantry, Position(3, 3));

    moveUnit(flying, Position(3, 3));
}

void GameController::runScenario3_NeutralObjectsAndOperators() {
    log("\n=== СЦЕНАРИЙ 3: Нейтральные объекты (Strategy) и Операторы ===");
    const auto& units = base->getActiveUnits();
    if (units.size() < 4) return;

    auto infantry = units[0];
    auto archer = units[1];
    auto mage = units[2];

    TreasureChest chest(base, 150);
    Trap trap(30);
    Altar altar;
    EnergySource source(40);

    log("--- Взаимодействие с сундуком (operator+) ---");
    infantry + chest;

    log("--- Взаимодействие с алтарем (operator* и выбор стратегии) ---");
    infantry * altar;
    archer * altar;
    mage * altar;     
    log("--- Взаимодействие с источником энергии (operator/) ---");
    mage / source;

    log("--- Попадание в ловушку (operator-) ---");
    infantry - trap;
}

void GameController::runScenario4_CombatAndObserver() {
    log("\n=== СЦЕНАРИЙ 4: Бой и гибель юнита с уведомлением Базы (Observer) ===");
    const auto& units = base->getActiveUnits();
    if (units.size() < 3) return;

    auto infantry = units[0];
    auto mage = units[2];

    log("Активных юнитов до боя: " + std::to_string(base->getActiveUnits().size()));

    mage->move(Position(0, 2));
    while (infantry->getHealth() > 0) {
        mage->attack(infantry);
    }

    log("Активных юнитов после гибели пехотинца: " + std::to_string(base->getActiveUnits().size()));
}

void GameController::run() {
    setupWorld();
    runScenario1_Creation();
    runScenario2_MovementAndProxy();
    runScenario3_NeutralObjectsAndOperators();
    runScenario4_CombatAndObserver();
}
