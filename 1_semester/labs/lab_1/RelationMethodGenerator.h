//
// Created by maxym_ko on 9/22/20.
//

#ifndef RELATION_METHOD_GENERATOR_H
#define RELATION_METHOD_GENERATOR_H


#include "RandomGenerator.h"
#include "InverseCongruentSequenceGenerator.h"

class RelationMethodGenerator : public RandomGenerator {
private:
    float x;
    InverseCongruentSequenceGenerator generator;
public:
    RelationMethodGenerator();

    float random() override;

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;

    float generate_u();
};


#endif //RELATION_METHOD_GENERATOR_H
