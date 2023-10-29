//
// Created by Marek Kolman on 2023-10-25.
//
#include "functions.h"
#include <iostream>

int main() {

    //std::variant<double, std::string> x = 5.0;

    std::vector<int> test = my_sum(10);

    std::any myAny = 10.0;
    int myDouble = std::any_cast<double>(myAny);

    int zz = std::any_cast<double>(myAny);

    std::cout << zz << std::endl;
    return 0;
}