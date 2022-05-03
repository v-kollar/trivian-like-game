//
// Created by User on 03.05.2022.
//

#include "Building.h"

Building::Building(std::string type, int locationRow, int locationCol, int level) {
    m_type = type;
    m_locationRow = locationRow;
    m_locationCol = locationCol;
    m_level = level;
}

std::string Building::getType() {
    return m_type;
}

int Building::getLocationRow() {
    return m_locationRow;
}

int Building::getLocationCol() {
    return m_locationCol;
}

int Building::getLevel() {
    return m_level;
}
