//
// Created by maxym_ko on 9/17/20.
//

#include <climits>
#include "InverseCongruentSequenceGenerator.h"
#include "PrimeFinder.h"

InverseCongruentSequenceGenerator::InverseCongruentSequenceGenerator() : a(13), c(17), x(0), m(11383) {
    x = generator.random_int();
}

int InverseCongruentSequenceGenerator::random_int() {
    return x = (a * mod_inv(x, m) + c) % m;
}

void InverseCongruentSequenceGenerator::set_max(int max) {
    m = PrimeFinder::maxPrime(max);
}

int InverseCongruentSequenceGenerator::get_max() {
    return m;
}

int InverseCongruentSequenceGenerator::mod_inv(int num, int mod) {
    if (num == 0) return INT_MAX;
    if (num == INT_MAX) return 0;
    num = num % mod;
    for (int i = 1; i < mod; i++) {
        if ((num * i) % mod == 1) return i;
    }
    return -1;
}