#include <utility>
#include "Building.h"


Building::Building(std::string type, int locationRow, int locationCol, int level) {
    m_type = std::move(type);
    m_locationRow = locationRow;
    m_locationCol = locationCol;
    m_level = level;
}

std::string Building::getType() {
    return m_type;
}

int Building::getLocationRow() const {
    return m_locationRow;
}

int Building::getLocationCol() const {
    return m_locationCol;
}

int Building::getLevel() const {
    return m_level;
}

void Building::levelUp() {
    m_level++;
}
