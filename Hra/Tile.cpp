#include "Tile.h"

Tile::Tile(std::string appearance){
    m_appearance = appearance;
}

std::string Tile::getAppearance(){
    return m_appearance;
}

void Tile::setAppearance(std::string appearance){
    m_appearance = appearance;
}
