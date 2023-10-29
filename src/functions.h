//
// Created by Marek Kolman on 2023-10-25.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <variant>
#include <any>
#include <optional>

std::vector<int> my_sum(int x);
double testfun(double x);
std::variant<int, std::string> xxx(std::variant<int, std::string> v);
std::optional<std::string> create(bool b);

double sum(double x, double y);

#endif

