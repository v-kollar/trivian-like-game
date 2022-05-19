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
    static bool isNumber(const std::string& s);
    static int selectDifficulty();
    static int selectPlayOrEnd();
    static int selectLocation(int difficulty);
    static int selectBuildingType();
    static int selectUpgradeOrCancel();
};


#endif //HRA_INPUT_H
