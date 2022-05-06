#include <iostream>
#include "GameEngine.h"
#include "Village.h"

GameEngine::GameEngine() {
    GameEngine::printIntro();

    std::cout << "Enter a difficulty: "; std::cin >> m_difficulty;
    m_village = new Village( m_difficulty * 5, (m_difficulty * 5 + 2), 5, 5, 5, 5 );

    GameEngine::play();
}

void GameEngine::setup() {
    // sets up the beginning of round?
}

int GameEngine::getDifficulty() const {
    return m_difficulty;
}

void GameEngine::printIntro() {
    std::cout << "Basic info about the game...\n"
              << "Select difficulty:\n"
              << "(1) easy\n"
              << "(2) medium\n"
              << "(3) hard\n\n";
}

void GameEngine::printOutro() {
    std::cout << "Some epic outro about not giving up and keep playing...\n";
}

void GameEngine::printMap() {
    std::cout << "Here is a map: \n";
    // prints a map
}

void GameEngine::play() {
    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
        int choice = 0;
        GameEngine::printMap();
        m_village->printResources();

        std::cout << "(1) end round \n"
        << "(2) play \n";
        std::cin >> choice;

        while (choice == 2) {
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
    GameEngine::printOutro();
}
