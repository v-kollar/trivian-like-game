//
// Created by User on 03.05.2022.
//

#include <iostream>
#include "ResourceTable.h"

ResourceTable::ResourceTable() {
    //instance nebudou existovat
}

std::vector<int> ResourceTable::getCostAndMaterial(std::string type) {
    if (type == "house") {
        std::vector<int> temp;
        temp.at(0) = 5;
        temp.at(1) = 5;
        temp.at(2) = 2;
        return temp;

    } else if (type == "quarry") {
        std::vector<int> temp;
        temp.at(0) = 2;
        temp.at(1) = 4;
        temp.at(2) = 5;

    } else if (type == "lumberjackhouse") {
        std::vector<int> temp;
        temp.at(0) = 5;
        temp.at(1) = 5;
        temp.at(2) = 2;

    } else if (type == "farm") {
        std::vector<int> temp;
        temp.at(0) = 5;
        temp.at(1) = 3;
        temp.at(2) = 2;

    } else {
        std::cerr << "Error -1: It is not possible to create other than the defined building types. Please contact the APP developers." << std::endl;
        return std::vector<int>();
    }
}

int ResourceTable::getProducetQty(Building *building) {
    if (building->getType() == "house") {
        return building->getLevel() * 5;

    } else if (building->getType() == "quarry") {
        return building->getLevel() * 10;

    } else if (building->getType() == "lumberjackhouse") {
        return building->getLevel() * 10;

    } else if (building->getType() == "farm") {
        return building->getLevel() * 10;

    } else {
        std::cerr << "Error -1: It is not possible to do this operation. Please contact the APP developers." << std::endl;
        return -1;
    }

}
