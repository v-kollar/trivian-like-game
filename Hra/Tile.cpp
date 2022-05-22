#include "Tile.h"

Tile::Tile(std::string appearance){
    m_appearance = appearance;
}

std::string Tile::getAppearance(){
    return m_appearance;
}
