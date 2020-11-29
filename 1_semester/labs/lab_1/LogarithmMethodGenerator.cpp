//
// Created by maxym_ko on 9/22/20.
//

#include <cmath>
#include "LogarithmMethodGenerator.h"

LogarithmMethodGenerator::LogarithmMethodGenerator() : u(10) {}

float LogarithmMethodGenerator::random() {
    float res = -u * log(generator.random());
    return res == INFINITY ? get_max() : res;
}

int LogarithmMethodGenerator::random_int() {
    return generator.random_int();
}

void LogarithmMethodGenerator::set_max(int max) {
    generator.set_max(max);
}

int LogarithmMethodGenerator::get_max() {
    return generator.get_max();
}