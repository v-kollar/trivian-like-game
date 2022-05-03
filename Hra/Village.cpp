//
// Created by adams on 02.05.2022.
//

#include <iostream>
#include "Village.h"

Village::Village(int minVillagers, int numOfVillagers, int wood, int stone, int iron, int wheat) {
    m_minVillagers = minVillagers;
    m_numOfVillagers = numOfVillagers;
    m_wood = wood;
    m_stone = stone;
    m_iron = iron;
    m_wheat = wheat;
}

int Village::getMinVillagers() {
    return m_minVillagers;
}

int Village::getNumOfVillagers() {
    return m_numOfVillagers;
}

void Village::checkTile() {
    int row;
    int col;
    int index = 0;
    bool check = false;
    std::cout << "Zadejte číslo řádku: " << std::endl;
    std::cin >> row;
    std::cout << "Zadejte číslo sloupce: " << std::endl;
    std::cin >> col;
    while (index != m_buildings.size()) {
        if (m_buildings.at(index)->Building::getLocationRow() == row && m_buildings.at(index)->Building::getLocationRow() == col ){
            check = true;
            break;
        }
        index += 1;
    }
    if (check){
        upgrade(m_buildings.at(index));
    } else{
        int type;
        std::string typeName = "";
        std::cout << "Vyberte typ budovy \n1 = farma\n2 = kamenolom\n3 = dum drevorubce \n4 = obytny dum";
        std::cin >> type;
        if (type == 1) {
            typeName = "farm";
        }
        if (type == 2) {
            typeName = "quarry";
        }
        if (type == 3) {
            typeName = "lumberjackhouse";
        }
        if (type == 4) {
            typeName = "house";
        } else{
            addBuilding(typeName,row,col);
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

void Village::upgrade(Building *building) {
    if (building->getType() == "farm"){
        if (m_iron>0 && m_stone>0 && m_wood>0){
            building->setLevel(building->getLevel()+1);
        }
    }
    if (building->getType() == "quarry"){
        if (m_iron>0 && m_stone>0 && m_wood>0){
            building->setLevel(building->getLevel()+1);
        }
    }
    if (building->getType() == "lumberjackhouse"){
        if (m_iron>0 && m_stone>0 && m_wood>0){
            building->setLevel(building->getLevel()+1);
        }
    }
    if (building->getType() == "house"){
        if (m_iron>0 && m_stone>0 && m_wood>0){
            building->setLevel(building->getLevel()+1);
        }
    }
}

void Village::addBuilding(std::string type, int locationRow, int locationCol) {
    std::vector<int> temp;
    temp = ResourceTable::getCostAndMaterial(type);
    if (m_wood>=temp.at(0) && m_stone>=temp.at(1) && m_iron>=temp.at(2)){
        m_wood -= temp.at(0);
        m_stone -= temp.at(1);
        m_iron -= temp.at(2);
        m_buildings.push_back(new Building(type,locationRow,locationCol,1));
        std::cout << "Dům postaven" << std::endl;
        //VYŘEŠIT NÁVRAT DO MENU
    } else{
        std::cout << "Nemáte dostatek surovin" << std::endl;
        //VYŘEŠIT NÁVRAT DO MENU
    }

}

void Village::addNewResources() {
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->getType()=="farm") {
            m_wheat += ResourceTable::getProducetQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType()=="quarry") {
            m_stone += ResourceTable::getProducetQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType()=="lumberjackhouse") {
            m_wood += ResourceTable::getProducetQty(m_buildings.at(i));
        }
        if (m_buildings.at(i)->getType()=="house") {
            m_numOfVillagers += ResourceTable::getProducetQty(m_buildings.at(i));
        }
    }
}
