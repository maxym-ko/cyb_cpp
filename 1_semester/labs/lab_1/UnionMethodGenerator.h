//
// Created by maxym_ko on 9/17/20.
//

#ifndef UNION_METHOD_GENERATOR_H
#define UNION_METHOD_GENERATOR_H

#include "LinearCongruentialGenerator.h"
#include "QuadraticCongruentialGenerator.h"

class UnionMethodGenerator : public RandomGenerator {
private:
    LinearCongruentialGenerator generator;
    QuadraticCongruentialGenerator generator2;
    unsigned int x;
    unsigned int y;
    int m; // big prime number
public:
    UnionMethodGenerator();

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //UNION_METHOD_GENERATOR_H
