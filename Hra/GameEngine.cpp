#include <iostream>
#include "GameEngine.h"
#include "Village.h"

GameEngine::GameEngine() {
    GameEngine::printIntro();

    std::cout << "Enter a difficulty: "; std::cin >> m_difficulty;

    m_village = new Village( m_difficulty * 5, 1, 5, 5, 5, 5 );
}

void GameEngine::setup() {
    // sets up the beginning of round?
}

void GameEngine::setDifficulty(int difficulty) {
    m_difficulty = difficulty;
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
// ?
//    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
//
//    }
}

void GameEngine::endRound() {
    // indicates, that round has ended
}
