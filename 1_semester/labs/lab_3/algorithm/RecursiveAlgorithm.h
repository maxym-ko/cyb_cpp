//
// Created by maxym_ko on 11/29/20.
//

#ifndef LAB_3_RECURSIVE_ALGORITHM_H
#define LAB_3_RECURSIVE_ALGORITHM_H


#include "../gui/animation/AnimationArea.h"

using namespace std;

class RecursiveAlgorithm {
private:
    static double area(Point a, Point b, Point c);

    static double distance(Point a, Point b);

    static double angle(Point a, Point b);

    static vector<Point> get_top_convex_hull(vector<Point> points, Point left_point, Point right_point,
                                             AnimationArea *animationArea, sf::RenderTarget &window);

    static vector<Point> get_bottom_convex_hull(vector<Point> points, Point left_point, Point right_point,
                                             AnimationArea *animationArea, sf::RenderTarget &window);

public:
    static vector<Point> get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window);
};


#endif //LAB_3_RECURSIVE_ALGORITHM_H
