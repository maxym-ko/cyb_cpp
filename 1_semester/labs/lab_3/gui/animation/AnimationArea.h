//
// Created by maxym_ko on 11/28/20.
//

#ifndef LAB_3_ANIMATION_WINDOW_H
#define LAB_3_ANIMATION_WINDOW_H


#include <SFML/Graphics.hpp>
#include <list>
#include "../../geo/Point.h"

class AnimationArea {
private:
    bool clicked;
    sf::RectangleShape boards;
    sf::RectangleShape points_area;
    std::vector<Point> points;
    std::vector<Point> convex_hull;
public:
    AnimationArea(float x, float y, float width, float height,
                  sf::Color outline_color, sf::Color fill_color, float thickness);

    void update(sf::Vector2f mouse_pos);

    void render(sf::RenderTarget &window);

    void clearArea(sf::RenderTarget &window);

    void drawAllPoints(sf::RenderTarget &window);

    void drawHullPoints(sf::RenderTarget &window);

    void drawHull(sf::RenderTarget &window);

    void start(const std::string& algorithm, sf::RenderTarget &window);

    void generate();

    void clear();

    void addPoint2Hull(Point point);
};


#endif //LAB_3_ANIMATION_WINDOW_H
