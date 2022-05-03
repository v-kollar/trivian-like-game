//
// Created by adams on 02.05.2022.
//

#ifndef HRA_VILLAGE_H
#define HRA_VILLAGE_H


#include <vector>
#include <string>
#include "Building.h"
#include "ResourceTable.h"

class Village {
    int m_minVillagers; //minimální počet vesničanů na dané kolo
    int m_numOfVillagers; //aktuální stav vesničanů pro toto kolo
    std::vector<Building*> m_buildings;
    int m_wood; //počet jednotek suroviny dřeva
    int m_stone; //počet jednotek suroviny kamene
    int m_iron; //počet jednotek suroviny železa
    int m_wheat; //počet jednotek suroviny obilí
public:
    Village(int minVillagers, int numOfVillagers, int wood, int stone, int iron, int wheat); //konstruktor třídy Village
    void checkTile(); //zkontroluje zda některá budova již nestojí na zadané souřadnici
    void addBuilding(std::string type, int locationRow, int locationCol); //přidá novou instanci třídy budovy do pole m_buildings
    void upgrade(Building* building); //vylepší některou z budov v poli m_buildings
    void setVillagers(int number); //nastaví hodnotu v proměnné m_numOfVillagers
    int getMinVillagers(); //vrátí hodnotu m_minVillagers
    int getNumOfVillagers(); //vratí hodnotu m_numOfVillagers
    void addNewResources(); //na konci kola přičte nově získáne suroviny k těm stávajícím

};


#endif //HRA_VILLAGE_H
