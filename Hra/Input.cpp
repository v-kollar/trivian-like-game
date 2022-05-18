//
// Created by User on 18.05.2022.
//

#include <iostream>
#include "Input.h"

Input::Input() {

}

int Input::selectChoice() {
    std::string temp;
    bool err = false;
    std::cout << ">";
    std::getline(std::cin, temp);
    //std::cout << "Pred podminkou: " << temp;



    if (isNumber(temp)) {
        //std::cout << "IF, " << isnumber(temp);
        return std::stoi(temp);
    } else {
        err = true;
        std::cout << "Enter the option number!\n";
        //std::cout << "ELSE, " << isnumber(temp);
    }

    while (err == true) {
        std::cout << ">";
        std::getline(std::cin, temp);
        if (isNumber(temp)) {
            err = false;
            return std::stoi(temp);
        } else {
            std::cout << "Enter the option number!\n";
        }
    }
}

int Input::selectPlayOrEnd() {
    int choice;
    bool err = false;
    std::cout << "(1) end round \n"
              << "(2) play \n";
    choice = Input::selectChoice();
    if (choice == 1 or choice == 2) {
        return choice;
    } else {
        std::cout << "Select (1) end round or (2) play...\n";
        err = true;
    }

    while (err == true) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) end round or (2) play...\n";
        }
    }
}

bool Input::isNumber(std::string s) {
    bool isnumber = true;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            isnumber = false;
    return isnumber;
}

int Input::selectDifficulty() {
    int choice;
    bool err = false;
    std::cout << "First, type the number of desired difficulty:\n"
                 "(1) easy\t(2) medium\t(3) hard\n\n";
    choice = Input::selectChoice();
    if (choice == 1 or choice == 2 or choice == 3) {
        return choice;
    } else {
        std::cout << "Select (1) easy or (2) medium or (3) hard...\n";
        err = true;
    }

    while (err == true) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2 or choice == 3) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) easy or (2) medium or (3) hard...\n";
        }
    }
}


