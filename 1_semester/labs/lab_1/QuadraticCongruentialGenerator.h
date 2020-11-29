//
// Created by maxym_ko on 9/17/20.
//

#ifndef QUADRATIC_CONGRUENTIAL_GENERATOR_H
#define QUADRATIC_CONGRUENTIAL_GENERATOR_H


#include <ctime>
#include "RandomGenerator.h"

class QuadraticCongruentialGenerator : public RandomGenerator {
private:
    unsigned int x;
    int m; // big prime number
    int a;
    int c;
    int d;
public:
    QuadraticCongruentialGenerator();

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //QUADRATIC_CONGRUENTIAL_GENERATOR_H
