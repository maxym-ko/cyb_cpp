//
// SimpleCreated by maxym_ko on 9/22/20.
//

#include <iostream>
#include <vector>
#include "Histogram.h"

void Histogram::printStat(RandomGenerator *generator, int min_interval, int max_interval, int count) {
    std::cout << "Interval     Frequency" << std::endl;

    std::vector<int> stat(10);
    if (count == 0) {
        count = generator->get_max();
    }
    for (int i = 0; i < count; i++) {
        float random = generator->random();
        random = (random - min_interval) / max_interval;
        int index = (int) (random * 10);
        stat[index]++;
    }

    float step = (max_interval - min_interval) / 10.;
    float curr_interval = min_interval;
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << curr_interval << "; " << curr_interval + step << "]   ";
        curr_interval += step;
        std::cout << (float) stat[i] / count << std::endl;
    }
}