//
// Created by adams on 02.05.2022.
//

#include <iostream>
#include <array>
#include <cassert>
#include "Village.h"
#include "GameEngine.h"

Village::Village(int difficulty, int minVillagers, int numOfVillagers,
                 int wood, int stone, int iron, int wheat) {
    m_difficulty = difficulty;
    m_minVillagers = minVillagers;
    m_numOfVillagers = numOfVillagers;
    m_wood = wood;
    m_stone = stone;
    m_iron = iron;
    m_wheat = wheat;
    m_freeSpace = 18/m_difficulty *18/m_difficulty;
    m_map = new Map(18/m_difficulty,18/m_difficulty);
}

int Village::getMinVillagers() const {
    return m_minVillagers;
}

int Village::getNumOfVillagers() const {
    return m_numOfVillagers;
}

void Village::checkTile() {
    int row; int col;
    int index = 0;
    bool isChecked = false;
    std::cout << "Input row number :";
    std::cin >> row;
    std::cout << "Input column number :";
    std::cin >> col;
    while (index != m_buildings.size()) {
        if (m_buildings.at(index)->Building::getLocationRow() == row
        and m_buildings.at(index)->Building::getLocationCol() == col){
            isChecked = true;
            break;
        }
        index += 1;
    }
    if (isChecked){
        upgrade(m_buildings.at(index));
    } else {
        int type;
        std::array<std::string, 4> types = {"farm", "quarry",
                                            "lumberjackhouse","house"};
        std::string typeName;
        Village::printResources();
        for (int i = 0; i < types.size(); ++i) {

            std::array<int, 3> temp;
            temp = ResourceTable::getCostAndMaterial(types.at(i));
            std::cout << "(" << i+1 << ") " << types.at(i) << " - requirements: " << temp.at(0)
                                     << " wood, " << temp.at(1)
                                     << " stone, " << temp.at(2) << " iron\n";
        }
        std::cout << ">";
        std::cin >> type;
        assert(typeid(type) == typeid(int));
        switch (type) {
            case 1:
                typeName = "farm";
                break;
            case 2:
                typeName = "quarry";
                break;
            case 3:
                typeName = "lumberjackhouse";
                break;
            case 4:
                typeName = "house";
                break;
            default:
                // everything not in range 1 to 4 goes here
                break;
        }
        addBuilding(typeName, row, col);
    }
}

void Village::upgrade(Building* building){
    if (building->getType() == "farm" ){
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            m_iron -= 0;
            m_stone -= 0;
            m_wood -= 0;
            building->levelUp();
            std::cout << "***Upgrade FINISHED***\n";
        } else {
            std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
        }
    }
    if (building->getType() == "quarry"){
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            m_iron -= 0;
            m_stone -= 0;
            m_wood -= 0;
            building->levelUp();
            std::cout << "***Upgrade FINISHED***\n";
        } else {
            std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
        }

    }
    if (building->getType() == "lumberjackhouse"){
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            m_iron -= 0;
            m_stone -= 0;
            m_wood -= 0;
            building->levelUp();
            std::cout << "***Upgrade FINISHED***\n";
        } else {
            std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
        }
    }
    if (building->getType() == "house"){
        if (m_iron > 0 and m_stone > 0 and m_wood > 0) {
            m_iron -= 0;
            m_stone -= 0;
            m_wood -= 0;
            building->levelUp();
            std::cout << "***Upgrade FINISHED***\n";
        } else {
            std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
        }
    }
}

void Village::addBuilding(std::string type, int locationRow, int locationCol) {
    std::array<int,3> temp;
    temp = ResourceTable::getCostAndMaterial(type);
    if (m_wood>=temp.at(0) and m_stone>=temp.at(1) and m_iron >= temp.at(2) and m_freeSpace>0){
        m_freeSpace -=1;
        m_wood -= temp.at(0);
        m_stone -= temp.at(1);
        m_iron -= temp.at(2);
        m_buildings.push_back(new Building(type, locationRow, locationCol,1));
        std::cout << "***Building FINISHED***\n";
        if (type == "farm"){
            m_map->setValue(locationRow,locationCol,Map::s_instanceFarm);
        }
        if (type == "quarry"){
            m_map->setValue(locationRow,locationCol,Map::s_instanceQuarry);
        }
        if (type == "lumberjackhouse"){
            m_map->setValue(locationRow,locationCol,Map::s_instanceLumberjackhouse);
        }
        if (type == "house") {
            m_map->setValue(locationRow,locationCol,Map::s_instanceHouse);
        }
    } else {
        std::cerr << "\n***You do NOT have ENOUGH RESOURCES or you are OUT OF SPACE!***\n";
    }

}

void Village::addNewResources() {
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->getType() == "farm") {
            m_wheat += ResourceTable::getProducetQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType() == "quarry") {
            m_stone += ResourceTable::getProducetQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType() == "lumberjackhouse") {
            m_wood += ResourceTable::getProducetQty(m_buildings.at(i));
        }
    }
}

void Village::printResources() const {
    std::cout << "***********Available resources**********\n"
    << m_wood << "x wood, " << m_stone << "x stone, "
    << m_iron << "x iron, " << m_wheat << "x wheat, "<< m_numOfVillagers << "x villager" <<"\n****************************************\n";
}

void Village::feedVillagers() {
    int requiredFood = 0;
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->getType() == "house"){
            requiredFood += ResourceTable::getProducetQty(m_buildings.at(i));
        }
    }
    if (m_numOfVillagers + requiredFood < m_wheat){
        m_numOfVillagers += requiredFood;
        m_wheat -= m_numOfVillagers + requiredFood;
    } else {
        m_numOfVillagers = m_wheat;
        m_wheat = 0;
    }
}

void Village::printMap() {
    m_map->show();
}