//
// Created by maxym_ko on 9/22/20.
//

#ifndef HISTOGRAM_H
#define HISTOGRAM_H


#include "RandomGenerator.h"

class Histogram {
public:
    static void printStat(RandomGenerator *generator, int min, int max, int count=0);
};


#endif //HISTOGRAM_H
