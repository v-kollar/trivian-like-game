#include <iostream>
#include "GameEngine.h"
#include "Village.h"
#include "Input.h"

GameEngine* GameEngine::s_engine = nullptr;

GameEngine::GameEngine() {
    GameEngine::printIntro();
    int chosenDifficulty = Input::selectDifficulty();
    m_village = new Village(chosenDifficulty, 1, (chosenDifficulty * 5),
                             200 / chosenDifficulty, 250 / chosenDifficulty,
                             200 / chosenDifficulty, 100 / chosenDifficulty);
    GameEngine::play();
}

GameEngine* GameEngine::getInstance() {
    if (s_engine == nullptr) {
        s_engine = new GameEngine();
    }
    return s_engine;
}

void GameEngine::printIntro() {
    std::cout << "\nWelcome player! This game is being made as school project\n"
                 "for course Basics of Object Design. Your goal is to build\n"
                 "and upgrade as many buildings as possible without losing\n"
                 "all your resources.\n"
                 "-------------------------------------------------------------\n"
                 "Here is a quick explanation of the game: \n"
                 "You can choose from 3 difficulty levels, each will determine size of the map, "
                 "how much villagers you will need per round and score multiplier\n"
                 "You can upgrade buildings up to 3 times.\n"
                 "Wood, stone and iron are resources used to build structures, weed is used for feeding villagers.\n"
                 "Each round the number of minimum villagers is raised so you need to build appropriate building to meet the quota.\n"
                 "Each building produces specific resources: house - villagers, quarry - stone + iron, lumberjack - wood, farm - weed.\n"
                 "Map size is determined by the selected difficulty.\n" << std::endl;
}


void GameEngine::play() {
    int choice;
    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
        m_village->setMinVillagers();
        m_village->printMap();
        m_village->printResources();

        choice = Input::selectPlayOrEnd();

        while (choice == 2) {
            m_village->printMap();
            m_village->checkTile();
            m_village->printResources();
            choice = Input::selectPlayOrEnd();
        }
        m_village->addNewResources();
        m_village->feedVillagers();

    }
    GameEngine::~GameEngine();
}


GameEngine::~GameEngine() {
    std::cout << "Your score is:" << m_village->getStats() << "\nBetter luck next time";
    delete m_village;
}