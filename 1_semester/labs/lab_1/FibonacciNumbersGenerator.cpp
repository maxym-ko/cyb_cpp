//
// Created by maxym_ko on 9/17/20.
//

#include "FibonacciNumbersGenerator.h"
#include "PrimeFinder.h"

FibonacciNumbersGenerator::FibonacciNumbersGenerator() : x_1(0), x_2(1), m(11383) {}

int FibonacciNumbersGenerator::random_int() {
    x_1 = x_2;
    return x_2 = (x_1 + x_2) % m;
}

void FibonacciNumbersGenerator::set_max(int max) {
    m = PrimeFinder::maxPrime(max);
}

int FibonacciNumbersGenerator::get_max() {
    return m;
}