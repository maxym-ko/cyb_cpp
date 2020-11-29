//
// Created by maxym_ko on 9/22/20.
//

#include <cmath>
#include "PrimeFinder.h"

int PrimeFinder::maxPrime(int max) {
    for (int i = max; i > 1; i--) {
        if (checkPrime(i)) return i;
    }
    return -1;
}

bool PrimeFinder::checkPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i < sqrt(num + 1); i++) {
        if (num % i == 0) return false;
    }
    return true;
}