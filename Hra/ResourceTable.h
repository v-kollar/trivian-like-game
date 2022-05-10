//
// Created by User on 03.05.2022.
//

#ifndef HRA_RESOURCETABLE_H
#define HRA_RESOURCETABLE_H


#include <vector>
#include <string>
#include <array>
#include "Building.h"

class ResourceTable {
    ResourceTable();
public:
    static std::array<int, 3> getCostAndMaterial(std::string type);
    static int getProducedQty(Building* building);
};


#endif //HRA_RESOURCETABLE_H
