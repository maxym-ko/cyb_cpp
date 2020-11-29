//
// Created by maxym_ko on 9/22/20.
//

#ifndef ARENS_METHOD_GENERATOR_H
#define ARENS_METHOD_GENERATOR_H


#include "RandomGenerator.h"
#include "LinearCongruentialGenerator.h"

class ArensMethodGenerator : public RandomGenerator {
private:
    float a;

    LinearCongruentialGenerator generator;
public:
    ArensMethodGenerator();

    float random() override;

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //ARENS_METHOD_GENERATOR_H
