//
// Created by maxym_ko on 9/22/20.
//

#include <iostream>
#include "SigmaMethodGenerator.h"

float SigmaMethodGenerator::random() {
    float sum = 0;
    for (int i = 0; i < 12; i++) {
        sum += generator.random();
    }
    return sum - 6;
}

int SigmaMethodGenerator::random_int() {
    return generator.random_int();
}

void SigmaMethodGenerator::set_max(int max) {
    generator.set_max(max);
}

int SigmaMethodGenerator::get_max() {
    return generator.get_max();
}