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
    static inline Tile* s_instanceFarm = new Tile("F");
    static inline Tile* s_instanceQuarry = new Tile("Q");
    static inline Tile* s_instanceLumberjackhouse = new Tile("L");
    static inline Tile* s_instanceHouse = new Tile("H");
    Map(unsigned int width, unsigned int height);
    void setValue(unsigned int row, unsigned int col, Tile *value);
    void show();
    ~Map();
};

#endif //HRA_MAP_H