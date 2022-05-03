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
    std::cout << "Zadejte cislo radku: " << std::endl;
    std::cin >> row;
    std::cout << "Zadejte cislo sloupce: " << std::endl;
    std::cin >> col;
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings.at(i)->Building::getLocationRow() == row && m_buildings.at(i)->Building::getLocationRow() == col ){
            upgrade(m_buildings.at(i));
        }
    }
    int type;
    std::string typeName;
    std::cout << "Vyberte typ budovy \n1 = farma\n2 = kamenolom\n3 = dum drevorubce \n4 = obytny dum";
    std::cin >> type;
    if (type == 1){
        typeName = "farm";
    }
    if (type == 2){
        typeName = "quarry";
    }
    if (type == 3){
        typeName = "lumberjackhouse";
    }
    if (type == 4){
        typeName = "house";
    }
    //přidat kontrolu
    addBuilding(typeName,row,col);

}

void Village::upgrade(Building *building) {

}

void Village::addBuilding(std::string type, int locationRow, int locationCol) {
    std::vector<int> temp;
    temp = ResourceTable::getCostAndMaterial(type);
    if (m_wood>=temp.at(0) && m_stone>=temp.at(1) && m_iron>=temp.at(2)){
        m_wood -= temp.at(0);
        m_stone -= temp.at(1);
        m_iron -= temp.at(2);
        m_buildings.push_back(new Building(type,locationRow,locationCol,1));
    } else{
        std::cout << "Nemate dostatek surovin" << std::endl;
    }


}
