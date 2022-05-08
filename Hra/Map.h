#ifndef HRA_MAP_H
#define HRA_MAP_H

#include <vector>
#include <iostream>
#include "Tile.h"

class Map {
    std::vector<std::vector<Tile*>> m_map;
    static bool isNonZero(unsigned int width, unsigned int height);
    bool isOnMap(unsigned int row, unsigned int col);
public:
    Map(unsigned int width, unsigned int height);
    Tile* getValue(unsigned int row, unsigned int col);
    void setValue(unsigned int row, unsigned int col, Tile* value);
    void setAppearance(unsigned row, unsigned col, std::string appearance);
    void show();
};

#endif //HRA_MAP_H
