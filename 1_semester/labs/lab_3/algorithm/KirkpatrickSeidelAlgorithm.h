//
// Created by maxym_ko on 11/25/20.
//

#ifndef LAB_3_KIRKPATRICKSEIDELALGORITHM_H
#define LAB_3_KIRKPATRICKSEIDELALGORITHM_H


#include <SFML/Graphics.hpp>
#include "../geo/Point.h"
#include "../gui/animation/AnimationArea.h"

using namespace std;

class KirkpatrickSeidelAlgorithm {
private:
    static vector<vector<Point>> bucketSort(const vector<Point>& points, unsigned int speed, sf::RenderTarget &window);

public:
    static vector<Point> get_convex_hull(const vector<Point>& points, AnimationArea *animationArea, sf::RenderTarget &window);

};


#endif //LAB_3_KIRKPATRICKSEIDELALGORITHM_H
