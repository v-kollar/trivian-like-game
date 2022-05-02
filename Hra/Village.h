//
// Created by adams on 02.05.2022.
//

#ifndef HRA_VILLAGE_H
#define HRA_VILLAGE_H


#include <vector>
#include "Building.h"

class Village {
    int m_minVillagers; //minimální počet vesničanů na dané kolo
    int m_numOfVillagers; //aktuální stav vesničanů pro toto kolo
    std::vector<Building*> m_buildings;
    int m_wood; //počet jednotek suroviny dřeva
    int m_stone; //počet jednotek suroviny kamene
    int m_iron; //počet jednotek suroviny železa
    int m_wheat; //počet jednotek suroviny obilí
public:
    Village(int minVillagers, int numOfVillagers, int wood, int stone, int iron, int wheat);
    void addBuilding();
    void upgrade();
    void setVillagers(int number);
    int getMinVillagers();
    int getNumOfVillagers();
    void addNewResources();

};


#endif //HRA_VILLAGE_H
