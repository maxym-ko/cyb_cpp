//
// Created by maxym_ko on 9/22/20.
//

#ifndef LOGARITHM_METHOD_GENERATOR_H
#define LOGARITHM_METHOD_GENERATOR_H


#include "RandomGenerator.h"
#include "LinearCongruentialGenerator.h"

class LogarithmMethodGenerator : public RandomGenerator {
private:
    float u;

    LinearCongruentialGenerator generator;
public:
    LogarithmMethodGenerator();

    float random() override;

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //LOGARITHM_METHOD_GENERATOR_H
