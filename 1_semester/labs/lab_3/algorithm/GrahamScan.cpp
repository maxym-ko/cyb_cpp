//
// Created by maxym_ko on 11/29/20.
//

#include "GrahamScan.h"
#include "../gui/animation/AnimationController.h"
#include <cmath>

struct sort_point_by_polar_angle {
    Point min_y;

    inline bool operator()(const Point &point1, const Point &point2) const {
        return atan2((point1.getY() - min_y.getY()), (min_y.getX() - point1.getX())) >
               atan2((point2.getY() - min_y.getY()), (min_y.getX() - point2.getX()));
    }
};

vector<Point> GrahamScan::get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

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
        AnimationController::animateLine(min_y, point, sf::Color::Green, 100, window);
    }
    for (Point point : points) {
        AnimationController::removeLine(min_y, point, window);
    }

    // start the algorithm
    convex_hull.push_back(min_y);
    convex_hull.push_back(points[0]);
    for (int i = 1; i < points.size(); i++) {
        while (convex_hull.size() > 1 &&
               ccw(convex_hull.rbegin()[1], convex_hull.rbegin()[0], points[i], window) <= 0) {
            convex_hull.pop_back();
        }
        convex_hull.push_back(points[i]);
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        AnimationController::drawLines(convex_hull, sf::Color::Red, window);
    }

    return convex_hull;
}

int GrahamScan::ccw(Point point1, Point point2, Point point3, sf::RenderTarget &window) {
    AnimationController::drawLine(point1, point2, sf::Color::Green, window);
    AnimationController::animateLine(point2, point3, sf::Color::Green, 300, window);
    AnimationController::drawLine(point1, point2, sf::Color::Blue, window);
    AnimationController::animateLine(point2, point3, sf::Color::Blue, 300, window);
    return (point2.getX() - point1.getX()) * (point3.getY() - point1.getY()) -
           (point2.getY() - point1.getY()) * (point3.getX() - point1.getX());
}
