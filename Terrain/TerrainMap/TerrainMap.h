#pragma once

#include "Terrain.h"
#include "Unit.h"
#include <vector>
#include <memory>

class TerrainMap {
private:
    int width;
    int height;
    std::vector<std::vector<std::unique_ptr<Terrain>>> grid;

public:
    TerrainMap(int width, int height);
    ~TerrainMap() = default;

    TerrainMap(const TerrainMap&) = delete;
    TerrainMap& operator=(const TerrainMap&) = delete;
    TerrainMap(TerrainMap&&) = default;
    TerrainMap& operator=(TerrainMap&&) = default;

    bool isValidPosition(int x, int y) const;
    bool isValidPosition(const Position& pos) const;

    void setTerrain(int x, int y, std::unique_ptr<Terrain> terrain);
    void setTerrain(const Position& pos, std::unique_ptr<Terrain> terrain);

    Terrain* getTerrain(int x, int y) const;
    Terrain* getTerrain(const Position& pos) const;

    int getWidth() const;
    int getHeight() const;
};
