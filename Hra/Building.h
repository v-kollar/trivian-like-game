//
// Created by User on 03.05.2022.
//

#ifndef HRA_BUILDING_H
#define HRA_BUILDING_H


#include <string>

class Building {
    std::string m_type;
    int m_locationRow;
    int m_locationCol;
    int m_level;
public:
    Building(std::string type, int locationRow, int locationCol, int level);
    std::string getType();
    int getLocationRow();
    int getLocationCol();
    int getLevel();
    void levelUp();
};


#endif //HRA_BUILDING_H
