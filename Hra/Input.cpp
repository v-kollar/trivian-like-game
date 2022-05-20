//
// Created by User on 18.05.2022.
//

#include <iostream>
#include "Input.h"

Input::Input() = default;

int Input::selectChoice() {
    std::string temp;
    bool err = false;
    std::cout << ">";
    std::getline(std::cin, temp);

    if (isNumber(temp)) {
        return std::stoi(temp);
    } else {
        err = true;
        std::cout << "Wrong input. Try again.\n";
    }

    while (err) {
        std::cout << ">";
        std::getline(std::cin, temp);
        if (isNumber(temp)) {
            err = false;
            return std::stoi(temp);
        } else {
            std::cout << "Wrong input. Try again.\n";
        }
    }
    return 0;
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

    while (err) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) end round or (2) play...\n";
        }
    }
}

bool Input::isNumber(const std::string& s) {
    if (!s.empty()) {
        for (char i : s)
            if (!isdigit(i))
                return false;
    } else {
        return false;
    }
    return true;
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

    while (err) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2 or choice == 3) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) easy or (2) medium or (3) hard...\n";
        }
    }
    return 0;
}

int Input::selectLocation(int difficulty) {
    int choice;
    bool err = false;
    choice = Input::selectChoice();
    if (choice >= 0 and choice < 18/(difficulty+1)+1) {
        return choice;
    } else {
        std::cout << " Oops! Selected number is not on the map! Try again\n";
        err = true;
    }

    while (err) {
        choice = Input::selectChoice();
        if (choice >= 0 and choice < 18 / (difficulty + 1) + 1) {
            err = false;
            return choice;
        } else {
            std::cout << " Oops! Selected number is not on the map! Try again\n";
        }
    }
    return 0;
}

int Input::selectBuildingType() {
    int choice;
    bool err = false;
    choice = Input::selectChoice();
    if (choice == 1 or choice == 2 or choice == 3 or choice == 4) {
        return choice;
    } else {
        std::cout << "Select (1) farm, (2) quarry, (3) lumberjackhouse, (4) house...\n";
        err = true;
    }

    while (err) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2 or choice == 3 or choice == 4) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) farm, (2) quarry, (3) lumberjackhouse, (4) house...\n";
        }
    }
    return 0;
}

int Input::selectUpgradeOrCancel() {
    int choice;
    bool err = false;
    std::cout << "(1) upgrade\t(2) cancel\n";
    choice = Input::selectChoice();
    if (choice == 1 or choice == 2) {
        return choice;
    } else {
        std::cout << "Select (1) upgrade or (2) cancel...\n";
        err = true;
    }

    while (err) {
        choice = Input::selectChoice();
        if (choice == 1 or choice == 2) {
            err = false;
            return choice;
        } else {
            std::cout << "Select (1) upgrade or (2) cancel...\n";
        }
    }
    return 0;
}
