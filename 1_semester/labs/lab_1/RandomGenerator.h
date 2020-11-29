//
// Created by maxym_ko on 9/22/20.
//

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H


class RandomGenerator {
public:
    virtual float random();

    virtual int random_int() = 0;

    virtual void set_max(int max) = 0;

    virtual int get_max() = 0;
};


#endif //RANDOM_GENERATOR_H
