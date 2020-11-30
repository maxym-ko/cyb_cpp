//
// Created by maxym_ko on 11/29/20.
//

#include <cmath>
#include <iostream>
#include "RecursiveAlgorithm.h"
#include "../gui/animation/AnimationController.h"
#include "JarvisAndrewAlgorithm.h"

vector<Point>
RecursiveAlgorithm::get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

    vector<Point> convex_hull;

    // sort by x and fin max and min Points by x
    sort(points.begin(), points.end(),
         [](const Point &point1, const Point &point2) { return point1.getX() < point2.getX(); });
    Point left_point = points.front();
    Point right_point = points.back();


    vector<Point> top_convex_hull = get_top_convex_hull(points, left_point, right_point, animationArea, window);
    top_convex_hull.push_back(left_point);
    sort(top_convex_hull.begin(), top_convex_hull.end(),
         [](const Point &point1, const Point &point2) { return point1.getX() < point2.getX(); });

    vector<Point> bottom_convex_hull = get_bottom_convex_hull(points, left_point, right_point, animationArea, window);
    bottom_convex_hull.push_back(right_point);
    sort(bottom_convex_hull.begin(), bottom_convex_hull.end(),
         [](const Point &point1, const Point &point2) { return point1.getX() < point2.getX(); });

    convex_hull.insert(convex_hull.end(), top_convex_hull.begin(), top_convex_hull.end());
    convex_hull.insert(convex_hull.end(), bottom_convex_hull.rbegin(), bottom_convex_hull.rend());

    return convex_hull;
}

vector<Point> RecursiveAlgorithm::get_top_convex_hull(vector<Point> points, Point left_point, Point right_point,
                                                      AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

    if (points.size() == 1) {
        animationArea->addPoint2Hull(points.back());
        return points;
    }

    unsigned int speed = points.size() > 100 ? 10000 / points.size() : 100;

    vector<Point> convex_hull;

    animationArea->clearArea(window);
    animationArea->drawAllPoints(window);
    animationArea->drawHullPoints(window);

    // separate point to top and bottom ones
    vector<Point> top_points;
    AnimationController::animateLine(left_point, right_point, sf::Color::Green, 300, window);
    for (int i = 0; i < points.size(); i++) {
        if (points[i] != left_point && points[i] != right_point &&
            JarvisAndrewAlgorithm::above_line(left_point, right_point, points[i])) {
            top_points.push_back(points[i]);
        }
    }


    // start the algorithm
    if (top_points.empty()) return {};

    Point h = top_points[0];
    double max_area = area(left_point, h, right_point);
    AnimationController::drawLine(left_point, h, sf::Color::Blue, window);
    AnimationController::drawLine(h, right_point, sf::Color::Blue, window);
    for (Point point : top_points) {
        double current_area = area(left_point, point, right_point);
        AnimationController::drawLine(left_point, right_point, sf::Color::Green, window);
        AnimationController::drawLine(left_point, point, sf::Color::Green, window);
        AnimationController::animateLine(point, right_point, sf::Color::Green, speed, window);
        AnimationController::removeLine(left_point, point, window);
        AnimationController::removeLine(point, right_point, window);
        if (current_area > max_area ||
            (current_area == max_area && angle(left_point, point) > angle(right_point, point))) {
            max_area = current_area;
            AnimationController::removeLine(left_point, h, window);
            AnimationController::removeLine(h, right_point, window);
            h = point;
        }
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        animationArea->drawHullPoints(window);
        AnimationController::drawLine(left_point, h, sf::Color::Blue, window);
        AnimationController::drawLine(h, right_point, sf::Color::Blue, window);
    }
    convex_hull.push_back(h);
    animationArea->addPoint2Hull(h);

    vector<Point> top_convex_hull_left = get_top_convex_hull(top_points, left_point, h, animationArea, window);
    convex_hull.insert(convex_hull.end(), top_convex_hull_left.begin(), top_convex_hull_left.end());

    vector<Point> top_convex_hull_tight = get_top_convex_hull(top_points, h, right_point, animationArea, window);
    convex_hull.insert(convex_hull.end(), top_convex_hull_tight.begin(), top_convex_hull_tight.end());

    return convex_hull;
}

vector<Point> RecursiveAlgorithm::get_bottom_convex_hull(vector<Point> points, Point left_point, Point right_point,
                                                         AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

    if (points.size() == 1) {
        animationArea->addPoint2Hull(points.back());
        return points;
    }

    unsigned int speed = points.size() > 100 ? 10000 / points.size() : 100;

    vector<Point> convex_hull;

    animationArea->clearArea(window);
    animationArea->drawAllPoints(window);
    animationArea->drawHullPoints(window);

    // separate point to top and bottom ones
    vector<Point> bottom_points;
    AnimationController::animateLine(left_point, right_point, sf::Color::Green, 300, window);
    for (int i = 0; i < points.size(); i++) {
        if (points[i] != left_point && points[i] != right_point &&
            !JarvisAndrewAlgorithm::above_line(left_point, right_point, points[i])) {
            bottom_points.push_back(points[i]);
        }
    }


    // start the algorithm

    if (bottom_points.empty()) return {};

    Point h = bottom_points[0];
    double max_area = area(left_point, h, right_point);
    AnimationController::drawLine(left_point, h, sf::Color::Blue, window);
    AnimationController::drawLine(h, right_point, sf::Color::Blue, window);
    for (Point point : bottom_points) {
        double current_area = area(left_point, point, right_point);
        AnimationController::drawLine(left_point, right_point, sf::Color::Green, window);
        AnimationController::drawLine(left_point, point, sf::Color::Green, window);
        AnimationController::animateLine(point, right_point, sf::Color::Green, speed, window);
        AnimationController::removeLine(left_point, point, window);
        AnimationController::removeLine(point, right_point, window);
        if (current_area > max_area ||
            (current_area == max_area && angle(left_point, point) > angle(right_point, point))) {
            max_area = current_area;
            AnimationController::removeLine(left_point, h, window);
            AnimationController::removeLine(h, right_point, window);
            h = point;
        }
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        animationArea->drawHullPoints(window);
        AnimationController::drawLine(left_point, h, sf::Color::Blue, window);
        AnimationController::drawLine(h, right_point, sf::Color::Blue, window);
    }
    convex_hull.push_back(h);
    animationArea->addPoint2Hull(h);

    vector<Point> bottom_convex_hull_left = get_bottom_convex_hull(bottom_points, left_point, h, animationArea, window);
    convex_hull.insert(convex_hull.end(), bottom_convex_hull_left.begin(), bottom_convex_hull_left.end());

    vector<Point> bottom_convex_hull_right = get_bottom_convex_hull(bottom_points, h, right_point, animationArea,
                                                                    window);
    convex_hull.insert(convex_hull.end(), bottom_convex_hull_right.begin(), bottom_convex_hull_right.end());

    return convex_hull;
}

double RecursiveAlgorithm::area(Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    double s = (ab + bc + ac) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}

double RecursiveAlgorithm::distance(Point a, Point b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

double RecursiveAlgorithm::angle(Point a, Point b) {
    return atan2((a.getY() - b.getY()), (b.getX() - a.getX()));
}
