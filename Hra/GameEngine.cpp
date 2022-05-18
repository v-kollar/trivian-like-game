#include <iostream>
#include <cassert>
#include "GameEngine.h"
#include "Village.h"
#include "Input.h"

GameEngine::GameEngine() {
    GameEngine::printIntro();

    int SelectedDifficulty = Input::selectDifficulty();

    m_village = new Village(SelectedDifficulty, 1, (SelectedDifficulty * 5 + 2),
                             300/SelectedDifficulty, 300/SelectedDifficulty, 300/SelectedDifficulty, 150/SelectedDifficulty);
    GameEngine::play();
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
    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
        int choice = 0;
        m_village->printMap();
        m_village->printResources();

        choice = Input::selectPlayOrEnd();

        while (choice == 2) {
            m_village->printMap();
            m_village->checkTile();
            m_village->printResources();
            choice = Input::selectPlayOrEnd();
        }
        m_village->feedVillagers();
        m_village->addNewResources();
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

