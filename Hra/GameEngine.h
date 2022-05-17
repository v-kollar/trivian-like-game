#ifndef ZOO_PROJECT_GAMEENGINE_H
#define ZOO_PROJECT_GAMEENGINE_H

#include "Village.h"

class GameEngine {
    Village* m_village;

public:
    GameEngine();
    int selectDifficulty();
    int selectPlayOrEnd();
    int selectChoice();
    static bool isnumber(const std::string& s);
    static void printIntro();
    static void printOutro();
    void play();
    ~GameEngine();
};

#endif //ZOO_PROJECT_GAMEENGINE_H
