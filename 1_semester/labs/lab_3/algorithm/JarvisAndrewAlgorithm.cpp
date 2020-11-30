//
// Created by maxym_ko on 11/26/20.
//

#include <algorithm>
#include <iostream>
#include "JarvisAndrewAlgorithm.h"
#include "../gui/animation/AnimationController.h"

using namespace std;

vector<Point> JarvisAndrewAlgorithm::get_convex_hull(vector<Point> points, AnimationArea *animationArea, sf::RenderTarget &window) {
    if (points.empty()) return {};

    unsigned int speed = points.size() > 50 ? 20000 / points.size() : 200;

    vector<Point> convex_hull;

    animationArea->clearArea(window);
    animationArea->drawAllPoints(window);
    animationArea->drawHullPoints(window);

    // sort by x and fin max and min Points by x
    sort(points.begin(), points.end(),
         [](const Point &point1, const Point &point2) { return point1.getX() < point2.getX(); });
    Point min_point = points.front();
    Point max_point = points.back();

    // separate point to top and bottom ones
    vector<Point> top_points, bottom_points;
    top_points.push_back(min_point);
    bottom_points.push_back(min_point);
    AnimationController::drawLine(min_point, max_point, sf::Color::Green, window);
    for (int i = 1; i < points.size() - 1; i++) {
        if (above_line(min_point, max_point, points[i])) {
            AnimationController::animatePoint(points[i].getX(), points[i].getY(), 2.f, sf::Color::Blue, speed / 2, window);
            top_points.push_back(points[i]);
        } else {
            AnimationController::animatePoint(points[i].getX(), points[i].getY(), 2.f, sf::Color::White, speed / 2, window);
            bottom_points.push_back(points[i]);
        }
    }
    top_points.push_back(max_point);
    bottom_points.push_back(max_point);

    // find top hull Points
    vector<Point> top_convex_hull = get_convex_hull(min_point, top_points, true, window);
    convex_hull.insert(convex_hull.end(), top_convex_hull.begin(), top_convex_hull.end());

    // find bottom hull Points
    vector<Point> bottom_convex_hull = get_convex_hull(min_point, bottom_points, false, window);
    convex_hull.insert(convex_hull.end(), bottom_convex_hull.rbegin() + 1, bottom_convex_hull.rend() - 1);

    return convex_hull;
}

bool JarvisAndrewAlgorithm::above_line(Point a, Point b, Point c) {
    int d = (c.getX() - a.getX()) * (b.getY() - a.getY()) -
            (c.getY() - a.getY()) * (b.getX() - a.getX());
    return d >= 0;
}

vector<Point>
JarvisAndrewAlgorithm::get_convex_hull(Point start_point, vector<Point> points, bool looking_for_top, sf::RenderTarget &window) {
    if (points.size() == 1) return points;

    unsigned int speed = points.size() > 50 ? 20000 / points.size() : 200;

    vector<Point> res_hull;
    bool point_is_suitable;
    Point current = start_point;
    for (int i = 1; i < points.size(); i++) {
        point_is_suitable = true;
        AnimationController::animateLine(current, points[i], sf::Color::Green, speed, window);
        for (int j = i + 1; j < points.size(); j++) {
            if ((looking_for_top && above_line(current, points[i], points[j])) ||
                    (!looking_for_top && !above_line(current, points[i], points[j]))) {
                point_is_suitable = false;
                break;
            }
        }
        if (point_is_suitable) {
            AnimationController::animateLine(current, points[i], sf::Color::Red, speed, window);
            res_hull.push_back(current);
            current = points[i];
        }
        AnimationController::removeLine(current, points[i], window);
    }
    res_hull.push_back(current);

    return res_hull;
}
