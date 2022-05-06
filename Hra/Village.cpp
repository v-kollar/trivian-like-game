//
// Created by adams on 02.05.2022.
//

#include <iostream>
#include <array>
#include "Village.h"

Village::Village(int minVillagers, int numOfVillagers, int wood, int stone, int iron, int wheat) {
    m_minVillagers = minVillagers;
    m_numOfVillagers = numOfVillagers;
    m_wood = wood;
    m_stone = stone;
    m_iron = iron;
    m_wheat = wheat;
}

int Village::getMinVillagers() const {
    return m_minVillagers;
}

int Village::getNumOfVillagers() const {
    return m_numOfVillagers;
}

void Village::checkTile() {
    int row;
    int col;
    int index = 0;
    bool isChecked = false;
    std::cout << "Input row number: \n";
    std::cin >> row;
    std::cout << "Input column number: \n";
    std::cin >> col;
    while (index != m_buildings.size()) {
        if (m_buildings.at(index)->Building::getLocationRow() == row
        and m_buildings.at(index)->Building::getLocationRow() == col){
            isChecked = true;
            break;
        }
        index += 1;
    }
    if (isChecked){
        upgrade(m_buildings.at(index));
    } else {
        int type;
        std::array<std::string, 4> types = {"farm", "quarry", "lumberjackhouse","house"};
        std::string typeName = "";
        std::cout << "Choose building type:\n" << std::endl;
        for (int i = 0; i < types.size(); ++i) {
            std::vector<int> temp;
            temp = ResourceTable::getCostAndMaterial(types.at(i));
            std::cout << types.at(i) << " - requirements: " << temp.at(0) << " wood, " << temp.at(1)
                                        << " stone, " << temp.at(2) << " iron" << std::endl;
        }
        /*
        std::cout << "Vyberte typ budovy \n1 = farma\n2 = kamenolom\n3 = dum drevorubce \n4 = obytny dum";
        */

        std::cin >> type;
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
                addBuilding(typeName, row, col);
        }
    }
    /*
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->Building::getLocationRow() == row && m_buildings.at(i)->Building::getLocationRow() == col ){
            upgrade(m_buildings.at(i));
        }
    }
    */
}

void Village::upgrade(Building* building) const {
    if (building->getType() == "farm"){
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){ //VYŘEŠIT JAK BUDE FUNGOVAT UPGRADE
            building->setLevel();
        }
    }
    if (building->getType() == "quarry"){ //VYŘEŠIT JAK BUDE FUNGOVAT UPGRADE
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            building->setLevel();
        }
    }
    if (building->getType() == "lumberjackhouse"){ //VYŘEŠIT JAK BUDE FUNGOVAT UPGRADE
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            building->setLevel();
        }
    }
    if (building->getType() == "house"){ //VYŘEŠIT JAK BUDE FUNGOVAT UPGRADE
        if (m_iron > 0 and m_stone > 0 and m_wood > 0){
            building->setLevel();
        }
    }
}

void Village::addBuilding(std::string type, int locationRow, int locationCol) {
    std::vector<int> temp;
    temp = ResourceTable::getCostAndMaterial(type);
    if (m_wood>=temp.at(0) and m_stone>=temp.at(1) and m_iron >= temp.at(2)){
        m_wood -= temp.at(0);
        m_stone -= temp.at(1);
        m_iron -= temp.at(2);
        m_buildings.push_back(new Building(type, locationRow, locationCol,1));
        std::cout << "Building finished\n";
        //VYŘEŠIT NÁVRAT DO MENU
    } else {
        std::cerr << "You don't have enough resources!\n";
        //VYŘEŠIT NÁVRAT DO MENU
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
        if (m_buildings.at(i)->getType() == "house") {
            m_numOfVillagers += ResourceTable::getProducetQty(m_buildings.at(i));
        }
    }
}

void Village::printResources() const {
    std::cout << "Available resources: \n"
    << m_wood << "x wood, " << m_stone << "x stone, " << m_iron << "x iron, " << m_wheat << "x wheat.\n\n";
}

void Village::feedVillagers() {
    if (m_numOfVillagers * 4 > m_wheat) {
        m_wheat -= m_numOfVillagers * 4;
    }
}
