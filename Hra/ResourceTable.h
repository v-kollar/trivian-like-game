//
// Created by User on 03.05.2022.
//

#ifndef HRA_RESOURCETABLE_H
#define HRA_RESOURCETABLE_H


#include <vector>
#include <string>
#include "Building.h"

class ResourceTable {
    ResourceTable();
public:
    static std::vector<int> getCostAndMaterial(std::string type);
    static int getProducetQty(Building* building);
};


#endif //HRA_RESOURCETABLE_H
