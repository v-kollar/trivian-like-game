#include <iostream>
#include "GameEngine.h"

GameEngine::GameEngine() = default;

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
    std::cout << "Some epic intro...\n";
}

void GameEngine::printInfo() {
    std::cout << "Info about the game...\n";
}

void GameEngine::printOutro() {
    std::cout << "Some epic outro about not giving up and keep playing...\n";
}

void GameEngine::printMap() {
    // prints a map
}

void GameEngine::play() {
    // ?
}

void GameEngine::endRound() {
    // indicates, that round has ended
}
