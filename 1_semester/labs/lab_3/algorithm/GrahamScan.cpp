//
// Created by maxym_ko on 11/29/20.
//

#include "GrahamScan.h"
#include "../gui/animation/AnimationController.h"
#include <cmath>
#include <iostream>

struct sort_point_by_polar_angle {
    Point min_y;

    inline bool operator()(const Point &point1, const Point &point2) const {
        return atan2((point1.getY() - min_y.getY()), (min_y.getX() - point1.getX())) >
               atan2((point2.getY() - min_y.getY()), (min_y.getX() - point2.getX()));
    }
};

vector<Point> GrahamScan::get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

    unsigned int speed = points.size() > 50 ? 20000 / points.size() : 200;

    vector<Point> convex_hull;

    animationArea->clearArea(window);
    animationArea->drawAllPoints(window);
    animationArea->drawHullPoints(window);

    // find the point with the lowest y-coordinate
    Point min_y = points[0];
    int min_index = 0;
    for (int i = 1; i < points.size(); i++) {
        if ((points[i].getY() < min_y.getY()) ||
            (points[i].getY() == min_y.getY() && points[i].getX() < min_y.getX())) {
            min_y = points[i];
            min_index = i;
        }
    }
    points.erase(points.begin() + min_index, points.begin() + min_index + 1);

    // sort points by polar angle
    sort_point_by_polar_angle comparator;
    comparator.min_y = min_y;
    sort(points.begin(), points.end(), comparator);

    for (Point point : points) {
        AnimationController::animateLine(min_y, point, sf::Color::Cyan, speed / 4, window);
    }
    for (Point point : points) {
        AnimationController::removeLine(min_y, point, window);
    }

    // start the algorithm
    convex_hull.push_back(min_y);
    convex_hull.push_back(points[0]);
    for (int i = 1; i < points.size(); i++) {
        while (convex_hull.size() > 1 &&
               ccw(convex_hull.rbegin()[1], convex_hull.rbegin()[0], points[i], speed, window) <= 0) {
            AnimationController::removeLine(convex_hull.rbegin()[1], convex_hull.rbegin()[0], window);
            AnimationController::removeLine(convex_hull.rbegin()[0], points[i],window);
            convex_hull.pop_back();
        }
        convex_hull.push_back(points[i]);
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        AnimationController::drawLines(convex_hull, sf::Color::Red, window);
    }

    return convex_hull;
}

int GrahamScan::ccw(Point a, Point b, Point c, unsigned int speed, sf::RenderTarget &window) {
    AnimationController::drawLine(a, b, sf::Color::Blue, window);
    AnimationController::animateLine(b, c, sf::Color::Blue, speed, window);
    return (b.getX() - a.getX()) * (c.getY() - a.getY()) -
           (b.getY() - a.getY()) * (c.getX() - a.getX());
}
