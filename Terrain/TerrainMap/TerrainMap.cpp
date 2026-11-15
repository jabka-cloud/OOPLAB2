#include "TerrainMap.h"
#include "Plains.h" 
#include <stdexcept>

TerrainMap::TerrainMap(int width, int height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Размеры карты должны быть положительными!");
    }

    grid.resize(height);
    for (int y = 0; y < height; ++y) {
        grid[y].reserve(width);
        for (int x = 0; x < width; ++x) {
            grid[y].push_back(std::make_unique<Plains>());
        }
    }
}

bool TerrainMap::isValidPosition(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void TerrainMap::setTerrain(int x, int y, std::unique_ptr<Terrain> terrain) {
    if (!isValidPosition(x, y)) {
        throw std::out_of_range("Координаты выходят за пределы карты при установке ландшафта!");
    }
    
    grid[y][x] = std::move(terrain);
}


Terrain* TerrainMap::getTerrain(int x, int y) const {
    if (!isValidPosition(x, y)) {
        return nullptr;
    }
    return grid[y][x].get();
}
Terrain* TerrainMap::getTerrain(const Position& pos) const {
    return getTerrain(pos.x, pos.y);
}

int TerrainMap::getWidth() const {
    return width;
}

int TerrainMap::getHeight() const {
    return height;
}
