//
// Created by maxym_ko on 9/17/20.
//

#ifndef FIBONACCI_NUMBERS_GENERATOR_H
#define FIBONACCI_NUMBERS_GENERATOR_H


#include <ctime>
#include "RandomGenerator.h"

class FibonacciNumbersGenerator: public RandomGenerator {
private:
    int x_1;
    int x_2;
    int m; // big prime number
public:
    FibonacciNumbersGenerator();

    int random_int() override;

    void set_max(int max) override;

    int get_max() override;
};


#endif //FIBONACCI_NUMBERS_GENERATOR_H
