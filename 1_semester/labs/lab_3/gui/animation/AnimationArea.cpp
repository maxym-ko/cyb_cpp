//
// Created by maxym_ko on 11/28/20.
//

#include <iostream>
#include "AnimationArea.h"
#include "AnimationController.h"
#include "../../algorithm/JarvisAndrewAlgorithm.h"
#include "../../algorithm/GrahamScan.h"
#include "../../algorithm/RecursiveAlgorithm.h"
#include "../../algorithm/KirkpatrickSeidelAlgorithm.h"

AnimationArea::AnimationArea(float x, float y, float width, float height, sf::Color outline_color,
                             sf::Color fill_color, float thickness) {
    clicked = false;

    boards.setFillColor(fill_color);
    boards.setOutlineColor(outline_color);
    boards.setOutlineThickness(thickness);
    boards.setPosition(sf::Vector2f(x, y));
    boards.setSize(sf::Vector2f(width, height));

    float padding_x = width / 18;
    float padding_y = height / 12;
    points_area.setFillColor(sf::Color::White);
    points_area.setPosition(sf::Vector2f(x + padding_x, y + padding_y));
    points_area.setSize(sf::Vector2f(width - 2 * padding_x, height - 2 * padding_y));

    AnimationController::delta_x = points_area.getPosition().x;
    AnimationController::delta_y = points_area.getPosition().y;

    Point::set_max_x(points_area.getGlobalBounds().width);
    Point::set_max_y(points_area.getGlobalBounds().height);
}

void AnimationArea::update(sf::Vector2f mouse_pos) {
    if (points_area.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!clicked) {
            points.emplace_back(mouse_pos.x - points_area.getPosition().x, mouse_pos.y - points_area.getPosition().y);
            convex_hull.clear();
        }
        clicked = true;
    } else {
        clicked = false;
    }
}

void AnimationArea::render(sf::RenderTarget &window) {
    clearArea(window);
    drawAllPoints(window);
    drawHullPoints(window);
    drawHull(window);
}

void AnimationArea::clearArea(sf::RenderTarget &window) {
    window.draw(boards);
}


void AnimationArea::drawAllPoints(sf::RenderTarget &window) {
    for (Point point : points) {
        AnimationController::drawPoint((float) point.getX(), (float) point.getY(),
                                       2.f, sf::Color(100, 250, 50), window);
    }
}

void AnimationArea::drawHullPoints(sf::RenderTarget &window) {
    for (Point point : convex_hull) {
        AnimationController::drawPoint((float) point.getX(), (float) point.getY(),
                                       3.f, sf::Color::Red, window);
    }
}

void AnimationArea::drawHull(sf::RenderTarget &window) {
    if (!convex_hull.empty()) {
        for (int i = 0; i < convex_hull.size() - 1; i++) {
            AnimationController::drawLine(convex_hull[i], convex_hull[i + 1], sf::Color::Red, window);
        }
        AnimationController::drawLine(convex_hull[0], convex_hull.back(), sf::Color::Red, window);
    }
}

void AnimationArea::start(const std::string &algorithm, sf::RenderTarget &window) {
    convex_hull.clear();
    if (algorithm == "1. Kirkpatrick-Seidel algorithm") {
        convex_hull = KirkpatrickSeidelAlgorithm::get_convex_hull(points, this, window);
    } else if (algorithm == "2. Jarvis-Andrew algorithm") {
        convex_hull = JarvisAndrewAlgorithm::get_convex_hull(points, this, window);
    } else if (algorithm == "3. Graham scan") {
        convex_hull = GrahamScan::get_convex_hull(points, this, window);
    } else if (algorithm == "4. Recursive algorithm") {
        convex_hull = RecursiveAlgorithm::get_convex_hull(points, this, window);
    }
}

void AnimationArea::generate() {
    convex_hull.clear();

    for (int i = 0; i < 50; i++) {
        points.emplace_back();
    }
}

void AnimationArea::clear() {
    convex_hull.clear();
    points.clear();
}

void AnimationArea::addPoint2Hull(Point point) {
    convex_hull.push_back(point);
}
