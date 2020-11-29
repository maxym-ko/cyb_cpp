//
// Created by maxym_ko on 9/17/20.
//

#ifndef INVERSE_CONGRUENT_SEQUENCE_GENERATOR_H
#define INVERSE_CONGRUENT_SEQUENCE_GENERATOR_H


#include "LinearCongruentialGenerator.h"
#include "RandomGenerator.h"

class InverseCongruentSequenceGenerator : public RandomGenerator {
private:
    int a;
    int c;
    int x;
    int m; // big prime number

    LinearCongruentialGenerator generator;
public:
    InverseCongruentSequenceGenerator();

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;

    static int mod_inv(int num, int mod);
};


#endif //INVERSE_CONGRUENT_SEQUENCE_GENERATOR_H
