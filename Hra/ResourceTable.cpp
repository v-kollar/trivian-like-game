//
// Created by User on 03.05.2022.
//

#include <iostream>
#include "ResourceTable.h"

ResourceTable::ResourceTable() {
    //instance nebudou existovat
}

std::array<int, 3> ResourceTable::getCostAndMaterial(std::string type) {
    std::array<int, 3> temp;
    if (type == "house") {
        temp.at(0) = 5;
        temp.at(1) = 5;
        temp.at(2) = 2;
        return temp;

    } else if (type == "quarry") {
        temp.at(0) = 2;
        temp.at(1) = 4;
        temp.at(2) = 5;
        return temp;

    } else if (type == "lumberjackhouse") {
        temp.at(0) = 5;
        temp.at(1) = 5;
        temp.at(2) = 2;
        return temp;

    } else if (type == "farm") {
        temp.at(0) = 5;
        temp.at(1) = 3;
        temp.at(2) = 2;
        return temp;

    } else {
        std::cerr << "Error -1: It is not possible to create other than the defined building types. Please contact the APP developers." << std::endl;
        return std::array<int, 3>();
    }
}

int ResourceTable::getProducedQty(Building *building) {
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
