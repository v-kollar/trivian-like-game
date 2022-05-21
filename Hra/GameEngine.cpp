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
                 "Here is a brief introduction to the game: \n"
                 "The player can choose from three difficulty levels, which will\n"
                 "determine the size of the playing area, how many villagers\n"
                 "will be needed per round and the score multiplier.\n"
                 "It is possible to upgrade each building a maximum of three times.\n"
                 "Wood, stone and iron are used to building, and weed is used to feed\n"
                 "the villagers. Each round increases the minimum number of villagers\n"
                 "so you need to think about, which buildings to build.\n"
                 "Each type of building produces unique recourses: house - villagers,\n"
                 "quarry - stone & iron, lumberjackhouse - wood and farm - weed\n\n";
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
    std::cout << "\nYour score is: " << m_village->getStats() << "\nBetter luck next time!\n";
    delete m_village;
}