//
// Created by User on 03.05.2022.
//

#include <iostream>
#include "ResourceTable.h"

ResourceTable::ResourceTable() = default;

std::array<int, 3> ResourceTable::getCostAndMaterial(const std::string& type) {
    std::array<int, 3> temp{};
    if (type == "house") {
        temp.at(0) = 35;
        temp.at(1) = 25;
        temp.at(2) = 30;
        return temp;

    } else if (type == "quarry") {
        temp.at(0) = 50;
        temp.at(1) = 40;
        temp.at(2) = 15;
        return temp;

    } else if (type == "lumberjackhouse") {
        temp.at(0) = 20;
        temp.at(1) = 50;
        temp.at(2) = 25;
        return temp;

    } else if (type == "farm") {
        temp.at(0) = 35;
        temp.at(1) = 45;
        temp.at(2) = 35;
        return temp;

    } else {
        std::cout << "Error 406: Cannot build other than pre-defined building types.\n";
        return {};
    }
}

int ResourceTable::getProducedQty(Building *building) {
    if (building->getType() == "house") {
        return building->getLevel() * 4;

    } else if (building->getType() == "quarry") {
        return building->getLevel() * 7;

    } else if (building->getType() == "lumberjackhouse") {
        return building->getLevel() * 7;

    } else if (building->getType() == "farm") {
        return building->getLevel() * 7;

    } else {
        std::cout << "Error 406: Operation rejected. Please, try again.\n";
        return -1;
    }
}
