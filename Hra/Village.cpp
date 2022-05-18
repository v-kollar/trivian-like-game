//
// Created by adams on 02.05.2022.
//

#include <iostream>
#include <array>
#include <cassert>
#include "Village.h"
#include "GameEngine.h"
#include "Input.h"

Village::Village(int difficulty, int minVillagers, int numOfVillagers,
                 int wood, int stone, int iron, int wheat) {
    m_difficulty = difficulty;
    m_minVillagers = minVillagers;
    m_numOfVillagers = numOfVillagers;
    m_wood = wood;
    m_stone = stone;
    m_iron = iron;
    m_wheat = wheat;
    m_freeSpace = (18/(m_difficulty+1)+1) * (18/(m_difficulty+1)+1);
    m_map = new Map(18/(m_difficulty+1)+1,18/(m_difficulty+1)+1);
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
    std::cout << "Input row number";
    row = Input::selectLocation(m_difficulty);
    std::cout << "Input column number";
    col = Input::selectLocation(m_difficulty);
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
        type = Input::selectBuildingType();
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
    std::string choice;
    if (building->getLevel()!= 3){
        if (building->getType() == "farm" ){
            std::cout << "***UPGRADE REQUIREMENTS - iron: " << (building->getLevel())*35 <<"x stone: " << (building->getLevel())*45 << "x wood: " << (building->getLevel())*35 << "x***"<< std::endl;
            std::cout << "(1) upgrade \n(2) cancel" << std::endl;
            std::cout << ">";
            std::getline(std::cin, choice);
            if (choice == "2") {
                std::cout << "***Upgrade CANCELED***" << std::endl;
            }
            else if (m_iron >= ((building->getLevel())*35) and m_stone >= ((building->getLevel())*45) and m_wood >= ((building->getLevel())*35) and choice == "1"){
                m_iron -= ((building->getLevel())*35);
                m_stone -= ((building->getLevel())*45);
                m_wood -= ((building->getLevel())*35);
                building->levelUp();
                std::cout << "***Upgrade FINISHED***\n";
            } else {
                std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";

            }

        }
        if (building->getType() == "quarry"){
            std::cout << "***UPGRADE REQUIREMENTS - iron: " << (building->getLevel())*15 <<"x stone: " << (building->getLevel())*40 << "x wood: " << (building->getLevel())*50 << "x***"<< std::endl;
            std::cout << "(1) upgrade \n(2) cancel" << std::endl;
            std::cout << ">";
            std::getline(std::cin, choice);
            if (choice == "2") {
                std::cout << "***Upgrade CANCELED***" << std::endl;
            }
            else if (m_iron >= ((building->getLevel())*15) and m_stone >= ((building->getLevel())*40) and m_wood >= ((building->getLevel())*50)){
                m_iron -= ((building->getLevel())*15);
                m_stone -= ((building->getLevel())*40);
                m_wood -= ((building->getLevel())*50);
                building->levelUp();
                std::cout << "***Upgrade FINISHED***\n";
            } else {
                std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
            }

        }
        if (building->getType() == "lumberjackhouse"){
            std::cout << "***UPGRADE REQUIREMENTS - iron: " << (building->getLevel())*25 <<"x stone: " << (building->getLevel())*50 << "x wood: " << (building->getLevel())*25 << "x***"<< std::endl;
            std::cout << "(1) upgrade \n(2) cancel" << std::endl;
            std::cout << ">";
            std::getline(std::cin, choice);
            if (choice == "2") {
                std::cout << "***Upgrade CANCELED***" << std::endl;
            }
            else if (m_iron >= ((building->getLevel())*25) and m_stone >= ((building->getLevel())*50) and m_wood >= ((building->getLevel())*25)){
                m_iron -= ((building->getLevel())*25) ;
                m_stone -= ((building->getLevel())*50);
                m_wood -= ((building->getLevel())*25);
                building->levelUp();
                std::cout << "***Upgrade FINISHED***\n";
            } else {
                std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
            }
        }
        if (building->getType() == "house"){
            std::cout << "***UPGRADE REQUIREMENTS - iron: " << (building->getLevel())*25 <<"x stone: " << (building->getLevel())*45 << "x wood: " << (building->getLevel())*35 << "x***"<< std::endl;
            std::cout << "(1) upgrade \n(2) cancel" << std::endl;
            std::cout << ">";
            std::getline(std::cin, choice);
            if (choice == "2") {
                std::cout << "***Upgrade CANCELED***" << std::endl;
            }
            else if (m_iron >= ((building->getLevel())*25) and m_stone >= ((building->getLevel())*45) and m_wood >= ((building->getLevel())*35)) {
                m_iron -= ((building->getLevel())*25);
                m_stone -= ((building->getLevel())*45);
                m_wood -= ((building->getLevel())*35);
                building->levelUp();
                std::cout << "***Upgrade FINISHED***\n";
            } else {
                std::cerr << "\n***You do NOT have ENOUGH RESOURCES FOR UPGRADE!***\n";
            }
        }
    } else{
        std::cout << "***This building is already at MAX LEVEL!***" << std::endl;
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
            m_wheat += ResourceTable::getProducedQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType() == "quarry") {
            m_stone += ResourceTable::getProducedQty(m_buildings.at(i));
            m_iron += ResourceTable::getProducedQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType() == "lumberjackhouse") {
            m_wood += ResourceTable::getProducedQty(m_buildings.at(i));
        }
    }
}

void Village::printResources() const {
    std::cout << "***********Available resources**********\n"
    << m_wood << "x wood, " << m_stone << "x stone, "
    << m_iron << "x iron, " << m_wheat << "x wheat, "<< m_numOfVillagers << "x villager" <<"\n****************************************\n" << "MINIMUM number of VILLAGERS FOR NEXT ROUND: " << m_minVillagers << "\n****************************************" <<std::endl;
}

void Village::feedVillagers() {
    int requiredFood = 0;
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->getType() == "house"){
            requiredFood += ResourceTable::getProducedQty(m_buildings.at(i));
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

void Village::setMinVillagers() {
    m_minVillagers += m_difficulty * 2;


}
