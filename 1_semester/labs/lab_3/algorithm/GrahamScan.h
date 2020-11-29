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
private:
    static int ccw(Point point1, Point point2, Point point3, sf::RenderTarget &window);

public:
    static vector<Point> get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window);

};


#endif //LAB_3_GRAHAM_SCAN_H
