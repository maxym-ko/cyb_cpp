//
// Created by maxym_ko on 9/22/20.
//

#include <cmath>
#include <iostream>
#include "RelationMethodGenerator.h"

RelationMethodGenerator::RelationMethodGenerator() : x(0) {}

float RelationMethodGenerator::random() {
    float v, u;
    float constant = sqrt(8 / exp(1));
    do {
        v = generator.random();
        u = generate_u();
        x = constant * (v - 0.5) / u;
        if (x * x <= 5 - 4 * exp(0.25) * u) return x;
    } while (x * x >= 4 * exp(-1.35) / u + 1.4 || x * x > -4 * log(u));
    return x;
}

int RelationMethodGenerator::random_int() {
    return generator.random_int();
}

void RelationMethodGenerator::set_max(int max) {
    generator.set_max(max);
}

int RelationMethodGenerator::get_max() {
    return generator.get_max();
}

float RelationMethodGenerator::generate_u() {
    float u;
    do {
        u = generator.random();
    } while (u == 0);
    return u;
}
