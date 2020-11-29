//)
// Created by maxym_ko on 9/17/20.
//

#include "LinearCongruentialGenerator.h"
#include "PrimeFinder.h"

LinearCongruentialGenerator::LinearCongruentialGenerator() : m(11383), a(13), c(7) {
    x = time(nullptr);
}

int LinearCongruentialGenerator::random_int() {
    return x = (a * x + c) % m;
}

void LinearCongruentialGenerator::set_max(int max) {
    m = PrimeFinder::maxPrime(max);
}

int LinearCongruentialGenerator::get_max() {
    return m;
}