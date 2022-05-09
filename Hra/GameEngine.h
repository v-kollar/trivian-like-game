#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    int m_difficulty;
    Village* m_village;

public:
    GameEngine();
    void setup();
    int getDifficulty() const;
    static void printIntro();
    static void printOutro();
    void printMap();  // to be added
    void play();
    void endRound();
    ~GameEngine();
};

#endif //ZOO_PROJECT_GAMEENGINE_H
