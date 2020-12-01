//
// Created by maxym_ko on 11/29/20.
//

#ifndef LAB_3_GRAHAM_SCAN_H
#define LAB_3_GRAHAM_SCAN_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "../geo/Point.h"
#include "../gui/animation/AnimationArea.h"

using namespace std;

class GrahamScan {
public:
    static vector<Point> get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window);

    // return signed area of triangle ABC (ccw > 0 - clockwise, ccw < 0 - anticlockwise, ccw = 0 - collinear)
    static int ccw(Point a, Point b, Point c, unsigned int speed, sf::RenderTarget &window);
};


#endif //LAB_3_GRAHAM_SCAN_H
