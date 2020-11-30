//
// Created by maxym_ko on 11/26/20.
//

#ifndef LAB_3_JARVIS_ANDREW_ANIMATION_H
#define LAB_3_JARVIS_ANDREW_ANIMATION_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "../geo/Point.h"
#include "../gui/animation/AnimationArea.h"

using namespace std;

class JarvisAndrewAlgorithm {
private:

    static vector<Point>
    get_convex_hull(Point start_point, vector<Point> points, bool looking_for_top, sf::RenderTarget &window);

public:
    // return true if Point c is above line that passed though Point a, Point b
    static bool above_line(Point a, Point b, Point c);

    static vector<Point> get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window);
};


#endif //LAB_3_JARVIS_ANDREW_ANIMATION_H
