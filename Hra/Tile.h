#ifndef HRA_TILE_H
#define HRA_TILE_H

#include <string>

class Tile {
    std::string m_appearance;
public:
    Tile(std::string appearance);
    std::string getAppearance();
    void setAppearance(std::string appearance);
};

#endif //HRA_TILE_H
