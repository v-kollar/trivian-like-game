#include <iostream>
#include <cassert>
#include "GameEngine.h"
#include "Village.h"

GameEngine::GameEngine() {
    GameEngine::printIntro();

    int SelectedDifficulty = selectDifficulty();

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


int GameEngine::selectDifficulty() {
    int choice;
    bool err = false;
    std::cout << "First, type the number of desired difficulty:\n"
                 "(1) easy\t(2) medium\t(3) hard\n\n";
    choice = GameEngine::selectChoice();
    if (choice == 1 or choice == 2 or choice == 3) {
        return choice;
    } else {
        std::cout << "Select (1) easy or (2) medium or (3) hard...\n";
        err = true;
    }

    while (err == true) {
        choice = GameEngine::selectChoice();
        if (choice == 1 or choice == 2 or choice == 3) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) easy or (2) medium or (3) hard...\n";
        }
    }
}


void GameEngine::play() {
    while (m_village->getNumOfVillagers() >= m_village->getMinVillagers()) {
        int choice = 0;
        m_village->printMap();
        m_village->printResources();

        choice = selectPlayOrEnd();

        while (choice == 2) {
            m_village->printMap();
            m_village->checkTile();
            m_village->printResources();
            choice = selectPlayOrEnd();
        }
        m_village->feedVillagers();
        m_village->addNewResources();
    }
    GameEngine::~GameEngine();
}


void GameEngine::printOutro() {
    std::cout << "Some epic outro about not giving up and keep playing...\n";
}


int GameEngine::selectChoice() {
    std::string temp;
    bool err = false;
    std::cout << ">";
    std::cin >> temp;

    if (isnumber(temp)) {
        return std::stoi(temp);
    } else {
        err = true;
        std::cout << "Enter the option number!\n";
    }

    while (err == true) {
        std::cout << ">";
        std::cin >> temp;
        if (isnumber(temp)) {
            err = false;
            return std::stoi(temp);
        } else {
            std::cout << "Enter the option number!\n";
        }
    }
}

int GameEngine::selectPlayOrEnd() {
    int choice;
    bool err = false;
    std::cout << "(1) end round \n"
              << "(2) play \n";
    choice = GameEngine::selectChoice();
    if (choice == 1 or choice == 2) {
        return choice;
    } else {
        std::cout << "Select (1) end round or (2) play...\n";
        err = true;
    }

    while (err == true) {
        choice = GameEngine::selectChoice();
        if (choice == 1 or choice == 2) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) end round or (2) play...\n";
        }
    }
}

bool GameEngine::isnumber(const std::string &s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
}


GameEngine::~GameEngine() {
    delete m_village;
    GameEngine::printOutro();
}

