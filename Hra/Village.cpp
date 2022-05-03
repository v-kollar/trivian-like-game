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
        if m_buildings.at(i)-> ==

    }

}
