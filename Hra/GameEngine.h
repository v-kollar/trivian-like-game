#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    Village* m_village;

public:
    GameEngine();
    static GameEngine* m_engine;
    static GameEngine* getInstance();
    static void printIntro();
    static void printOutro();
    void play();
    ~GameEngine();
};

#endif //ZOO_PROJECT_GAMEENGINE_H
