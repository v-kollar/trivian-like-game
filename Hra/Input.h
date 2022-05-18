//
// Created by User on 18.05.2022.
//

#ifndef HRA_INPUT_H
#define HRA_INPUT_H


#include <string>

class Input {
    Input();
public:
    static int selectChoice();
    static bool isNumber(std::string s);
    static int selectDifficulty();
    static int selectPlayOrEnd();
    static int selectLocation(int difficulty);
    static int selectBuildingType();
};


#endif //HRA_INPUT_H
