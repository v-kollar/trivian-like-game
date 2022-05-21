#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    Village* m_village;
    GameEngine();
public:
    static GameEngine* s_engine;
    static GameEngine* getInstance();
    static void printIntro();
    void play();
    ~GameEngine();
};

#endif //ZOO_PROJECT_GAMEENGINE_H
