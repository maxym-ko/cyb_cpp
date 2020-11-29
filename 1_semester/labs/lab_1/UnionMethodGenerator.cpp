//
// Created by maxym_ko on 9/17/20.
//

#include "UnionMethodGenerator.h"
#include "LinearCongruentialGenerator.h"
#include "QuadraticCongruentialGenerator.h"
#include "PrimeFinder.h"

UnionMethodGenerator::UnionMethodGenerator() : x(0), y(0), m(11383) {
    generator = LinearCongruentialGenerator();
    generator2 = QuadraticCongruentialGenerator();
}

int UnionMethodGenerator::random_int() {
    x = generator.random_int();
    y = generator2.random_int();
    return (x - y + m) % m;
}

void UnionMethodGenerator::set_max(int max) {
    m = PrimeFinder::maxPrime(max);
}

int UnionMethodGenerator::get_max() {
    return m;
}
