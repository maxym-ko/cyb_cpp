//
// Created by maxym_ko on 11/28/20.
//

#ifndef LAB_3_ANIMATIONCONTROLLER_H
#define LAB_3_ANIMATIONCONTROLLER_H


#include <SFML/Graphics.hpp>
#include "../../geo/Point.h"

class AnimationController {
public:
    static float delta_x;
    static float delta_y;

    static void drawPoint(float x, float y, float radius, sf::Color color, sf::RenderTarget &window);

    static void drawPoints(std::vector<Point> points, float radius, sf::Color color, sf::RenderTarget &window);

    static void drawLine(Point a, Point b, sf::Color color, sf::RenderTarget &window);

    static void drawLines(std::vector<Point> points, sf::Color color, sf::RenderTarget &window);

    static void removeLine(Point a, Point b, sf::RenderTarget &window);

    static void animatePoint(float x, float y, float radius, sf::Color color, unsigned int speed, sf::RenderTarget &window);

    static void animateLine(Point a, Point b, sf::Color color, unsigned int speed, sf::RenderTarget &window);

    static void wait(unsigned int msec);
};


#endif //LAB_3_ANIMATIONCONTROLLER_H
