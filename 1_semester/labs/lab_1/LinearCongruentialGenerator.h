//
// Created by maxym_ko on 9/17/20.
//

#ifndef LINEAR_CONGRUENTIAL_GENERATOR_H
#define LINEAR_CONGRUENTIAL_GENERATOR_H


#include <ctime>
#include "RandomGenerator.h"

class LinearCongruentialGenerator : public RandomGenerator {
private:
    unsigned int x;
    int m = 11383; // big prime number
    int a = 13;
    int c = 7;
public:
    LinearCongruentialGenerator();

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //LINEAR_CONGRUENTIAL_GENERATOR_H
