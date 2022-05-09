#include <iostream>
#include <cassert>
#include "GameEngine.h"
#include "Village.h"

GameEngine::GameEngine() {
    m_difficulty = 0;
    GameEngine::printIntro();
    std::cout << ">";
    std::cin >> m_difficulty;
    assert(m_difficulty >= 1 and m_difficulty <= 3);

    m_village = new Village( m_difficulty * 5, (m_difficulty * 5 + 2),
                             15, 5, 5, 5 );
    GameEngine::play();
}

void GameEngine::setup() {
    // sets up the beginning of round?
}

int GameEngine::getDifficulty() const {
    return m_difficulty;
}

void GameEngine::printIntro() {
    std::cout << "\nWelcome player! This game is being made as school project\n"
                 "for course Basics of Object Design. Your goal is to build\n"
                 "and upgrade as many buildings as possible without lossing\n"
                 "all your resources.\n"
                 "-------------------------------------------------------------\n"
                 "Map size is determined by the selected difficulty.\n" // sizes of each difficulties
                 "First, type the number of desired difficulty:\n"
                 "(1) easy\t(2) medium\t(3) hard\n\n";
}

void GameEngine::printOutro() {
    std::cout << "Some epic outro about not giving up and keep playing...\n";
}

void GameEngine::printMap() {
    std::cout << "This is what the world map looks like at the moment: \n"
              << "### here player will see an epic map ###\n\n";  // prints a map
}

void GameEngine::play() {
    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
        int choice = 0;
        m_village->printMap();
        m_village->printResources();

        std::cout << "(1) end round \n"
                  << "(2) play \n";

        std::cin >> choice;

        while (choice == 2) {
            m_village->printMap();
            m_village->checkTile();
            std::cout << "(1) end round \n"
                      << "(2) play \n";
            std::cin >> choice;
        }
        m_village->feedVillagers();
        m_village->addNewResources();
    }
    GameEngine::~GameEngine();
}

void GameEngine::endRound() {
    // indicates, that round has ended
}

GameEngine::~GameEngine() {
    delete m_village;
    GameEngine::printOutro();
}
