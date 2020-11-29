//
// Created by maxym_ko on 9/22/20.
//

#include "RandomGenerator.h"

float RandomGenerator::random() {
    return (float) random_int() / get_max();
}