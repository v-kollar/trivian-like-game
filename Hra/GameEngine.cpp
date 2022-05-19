#include <iostream>
#include <cassert>
#include "GameEngine.h"
#include "Village.h"
#include "Input.h"

GameEngine* GameEngine::m_engine = nullptr;

GameEngine::GameEngine() {
    GameEngine::printIntro();

    int chosenDifficulty = Input::selectDifficulty();

    m_village = new Village(chosenDifficulty, 1, (chosenDifficulty * 5 + 2),
                             300/chosenDifficulty, 300/chosenDifficulty, 300/chosenDifficulty, 150/chosenDifficulty);
    GameEngine::play();
}

GameEngine* GameEngine::getInstance() {
    if (m_engine == nullptr) {
        m_engine = new GameEngine();
    }
    return m_engine;
}

void GameEngine::printIntro() {
    std::cout << "\nWelcome player! This game is being made as school project\n"
                 "for course Basics of Object Design. Your goal is to build\n"
                 "and upgrade as many buildings as possible without lossing\n"
                 "all your resources.\n"
                 "-------------------------------------------------------------\n"
                 "Map size is determined by the selected difficulty.\n"; // sizes of each difficulties

}


void GameEngine::play() {
    int choice = 0;
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


void GameEngine::printOutro() {
    std::cout << "Some epic outro about not giving up and keep playing...\n";
}

GameEngine::~GameEngine() {
    delete m_village;
    GameEngine::printOutro();
}

