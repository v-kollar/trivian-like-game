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
};


#endif //HRA_INPUT_H
