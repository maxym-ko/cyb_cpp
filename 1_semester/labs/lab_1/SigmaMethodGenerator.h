//
// Created by maxym_ko on 9/22/20.
//

#ifndef SIGMA_METHOD_GENERATOR_H
#define SIGMA_METHOD_GENERATOR_H


#include "RandomGenerator.h"
#include "QuadraticCongruentialGenerator.h"

class SigmaMethodGenerator : public RandomGenerator {
private:
    int tmp=0;
    QuadraticCongruentialGenerator generator;
public:
    float random() override;

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //SIGMA_METHOD_GENERATOR_H
