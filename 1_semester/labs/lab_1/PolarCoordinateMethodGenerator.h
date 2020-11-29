//
// Created by maxym_ko on 9/22/20.
//

#ifndef POLAR_COORDINATE_METHOD_GENERATOR_H
#define POLAR_COORDINATE_METHOD_GENERATOR_H


#include "InverseCongruentSequenceGenerator.h"
#include "RandomGenerator.h"

class PolarCoordinateMethodGenerator : public RandomGenerator {
private:
    float v_1;
    float v_2;
    float s;
    float x_1;
    float x_2;
    bool last_x_1;
    InverseCongruentSequenceGenerator generator;
public:
    PolarCoordinateMethodGenerator();

    float random() override;

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //POLAR_COORDINATE_METHOD_GENERATOR_H
