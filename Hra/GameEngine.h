#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    Village* m_village;
    static GameEngine* s_engine;
    GameEngine();
public:
    static GameEngine* getInstance();
    void printIntro();
    void play();
    ~GameEngine();
};

#endif //ZOO_PROJECT_GAMEENGINE_H
