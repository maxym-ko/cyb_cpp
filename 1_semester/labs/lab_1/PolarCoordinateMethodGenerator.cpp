//
// Created by maxym_ko on 9/22/20.
//

#include <cmath>
#include <iostream>
#include "PolarCoordinateMethodGenerator.h"

PolarCoordinateMethodGenerator::PolarCoordinateMethodGenerator() : v_1(0), v_2(0), s(0), x_1(0), x_2(0),
                                                                   last_x_1(false) {
    generator = InverseCongruentSequenceGenerator();
}

float PolarCoordinateMethodGenerator::random() {
    do {
        v_1 = 2 * generator.random() - 1;
        v_2 = 2 * generator.random() - 1;

        s = v_1 * v_1 + v_2 * v_2;
    } while (s >= 1);
    x_1 = v_1 * sqrt(-2 * log(s) / s);
    x_2 = v_2 * sqrt(-2 * log(s) / s);
    last_x_1 = !last_x_1;
    return !last_x_1 ? x_2 : x_1;
}


int PolarCoordinateMethodGenerator::random_int() {
    return generator.random_int();
}

void PolarCoordinateMethodGenerator::set_max(int max) {
    generator.set_max(max);
}

int PolarCoordinateMethodGenerator::get_max() {
    return generator.get_max();
}
