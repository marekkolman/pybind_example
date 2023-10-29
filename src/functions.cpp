#include "functions.h"

std::vector<int> my_sum(int x)
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(11);
    return v;
}

double testfun(double x)
{
    std::any myAny = x;
    double zz = std::any_cast<double>(myAny);
    return zz;
}

std::variant<int, std::string> xxx(std::variant<int, std::string> v)
{
    return v;
}

std::optional<std::string> create(bool b)
{
    if (b)
        return "Godzilla";
    return {};
}

double sum(double x, double y){
    return x+y;
}

//
// Created by Marek Kolman on 2023-10-25.
//
