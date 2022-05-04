#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    int m_difficulty;
    Village* m_village;

public:
    GameEngine()
    void setup()
    void setDifficulty(int difficulty)
    int getDifficulty()
    void printIntro()
    void printInfo()
    void printOutro()
    void printMap()  // to be added
    void play()
    void endRound()
};

#endif //ZOO_PROJECT_GAMEENGINE_H
