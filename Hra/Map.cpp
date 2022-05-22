#include "Map.h"

bool Map::isNonZero(unsigned int width, unsigned int height) {
    if (width == 0) {
        std::cout << "Map::isNonZero: width must not be zero!\n";
        return false;
    }
    if (height == 0) {
        std::cout << "Map::isNonZero: height must not be zero!\n";
        return false;
    }
    return true;
}

bool Map::isOnMap(unsigned int row, unsigned int col) {
    if (row >= m_map.size()) {
        std::cout << "Map::isOnMap: entered a row value that is too large, "
                 << "maximum is " << m_map.size() - 1 << "\n\n";
        return false;
    }
    if (col >= m_map.size()) {
        std::cout << "Map::isOnMap: entered a column value that is too large, "
                  << "maximum is " << m_map.size() - 1 << "\n\n";
        return false;
    }
    return true;
}

Map::Map(unsigned int width, unsigned int height) {
    if (isNonZero(width, height)) {
        for (int i = 0; i < height; ++i) {
            std::vector<Tile*> row(width, new Tile("."));
            m_map.push_back(row);
        }
    } else {
        std::vector<Tile*> row(1, new Tile(" . "));
        std::vector<std::vector<Tile*>> map(1, row);
        m_map = map;
    }
}

void Map::setValue(unsigned int row, unsigned int col, Tile *value) {
    if (isOnMap(row, col)) {
        m_map.at(row).at(col) = value;
    }
}

void Map::show() {
    for (const std::vector<Tile*>& row : m_map) {
        for (Tile* cell : row) {
            std::cout << cell->getAppearance() << "  ";
        }
        std::cout << "\n";
    }
}

Map::~Map() {

}
