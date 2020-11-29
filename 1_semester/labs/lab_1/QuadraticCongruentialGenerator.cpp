//
// Created by maxym_ko on 9/17/20.
//

#include "QuadraticCongruentialGenerator.h"
#include "PrimeFinder.h"

QuadraticCongruentialGenerator::QuadraticCongruentialGenerator() : m(11833), a(13), c(7), d(8) {
    x = time(nullptr);
}

int QuadraticCongruentialGenerator::random_int() {
    return x = (d * x * x + a * x + c) % m;
}

void QuadraticCongruentialGenerator::set_max(int max) {
    m = PrimeFinder::maxPrime(max);
}

int QuadraticCongruentialGenerator::get_max() {
    return m;
}