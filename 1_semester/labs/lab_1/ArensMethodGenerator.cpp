//
// Created by maxym_ko on 9/22/20.
//

#include <cmath>
#include "ArensMethodGenerator.h"

ArensMethodGenerator::ArensMethodGenerator() : a(56) {}

float ArensMethodGenerator::random() {
    float u, y, x, v;
    do {
        do {
            u = generator.random();
            y = tan(M_PI * u);
            x = sqrt(2 * a - 1) * y + a - 1;;
        } while (x <= 0);
        v = generator.random();
    } while (v > (1 + y * y) * exp((a - 1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y));
    return x;
}

int ArensMethodGenerator::random_int() {
    return generator.random_int();
}

void ArensMethodGenerator::set_max(int max) {
    generator.set_max(max);
}

int ArensMethodGenerator::get_max() {
    return generator.get_max();
}