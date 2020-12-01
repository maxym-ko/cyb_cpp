//
// Created by maxym_ko on 11/25/20.
//
using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include "KirkpatrickSeidelAlgorithm.h"
#include "../gui/animation/AnimationController.h"
#include "GrahamScan.h"

struct sort_point_by_x {
    inline bool operator()(const Point &point, const Point &point2) {
        return (point.getX() < point2.getX());
    }
};

vector<Point> KirkpatrickSeidelAlgorithm::get_convex_hull(const vector<Point>& points, AnimationArea *animationArea,
                                                          sf::RenderTarget &window) {
    if (points.empty()) return {};

    unsigned int speed = points.size() > 50 ? 20000 / points.size() : 200;

    vector<Point> convex_hull;

    vector<vector<Point>> points_sorted = bucketSort(points, speed, window);

    vector<Point> points_left = points_sorted[0];
    vector<Point> points_right = points_sorted[1];


    // start the algorithm
    vector<Point> convex_hull_left;
    vector<Point> convex_hull_right;

    convex_hull_left.push_back(points_left[0]);
    convex_hull_left.push_back(points_left[1]);
    for (int i = 2; i < points_left.size(); i++) {
        while (convex_hull_left.size() > 1 &&
               GrahamScan::ccw(convex_hull_left.rbegin()[1], convex_hull_left.rbegin()[0], points_left[i], speed, window) >= 0) {
            AnimationController::removeLine(convex_hull_left.rbegin()[1], convex_hull_left.rbegin()[0], window);
            AnimationController::removeLine(convex_hull_left.rbegin()[0], points_left[i],window);
            convex_hull_left.pop_back();
        }
        convex_hull_left.push_back(points_left[i]);
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        AnimationController::drawLines(convex_hull_left, sf::Color::Red, window);
    }

    convex_hull_right.push_back(points_right[0]);
    convex_hull_right.push_back(points_right[1]);
    for (int i = 2; i < points_right.size(); i++) {
        while (convex_hull_right.size() > 1 &&
               GrahamScan::ccw(convex_hull_right.rbegin()[1], convex_hull_right.rbegin()[0], points_right[i], speed, window) <= 0) {
            AnimationController::removeLine(convex_hull_right.rbegin()[1], convex_hull_right.rbegin()[0], window);
            AnimationController::removeLine(convex_hull_right.rbegin()[0], points_right[i],window);
            convex_hull_right.pop_back();
        }
        convex_hull_right.push_back(points_right[i]);
        animationArea->clearArea(window);
        animationArea->drawAllPoints(window);
        AnimationController::drawLines(convex_hull_right, sf::Color::Red, window);
    }


    convex_hull.insert(convex_hull.end(), convex_hull_left.begin(), convex_hull_left.end());
    convex_hull.insert(convex_hull.end(), convex_hull_right.rbegin(), convex_hull_right.rend());

    return convex_hull;
}

vector<vector<Point>> KirkpatrickSeidelAlgorithm::bucketSort(const vector<Point>& points, unsigned int speed, sf::RenderTarget &window) {
    int buckets_amount = Point::get_max_y() + 1;

    vector<Point> buckets[buckets_amount];
    for (Point point : points) {
        buckets[point.getY() % buckets_amount].push_back(point);
    }

    for (int i = 0; i < buckets_amount; i++) {
        sort(buckets[i].begin(), buckets[i].end(), sort_point_by_x());
    }

    int max_x = Point::get_max_x();
    vector<Point> points_left;
    vector<Point> points_right;
    for (int i = 0; i < buckets_amount; i++) {
        if (buckets[i].empty()) continue;

        if (buckets[i].size() == 1) {
            Point point = buckets[i].front();
            if (point.getX() < max_x / 2) {
                points_left.push_back(buckets[i].front());
                AnimationController::animatePoint(buckets[i].front().getX(), buckets[i].front().getY(), 2.f, sf::Color::Blue,
                                                  speed / 2, window);
            } else {
                points_right.push_back(buckets[i].back());
                AnimationController::animatePoint(buckets[i].back().getX(), buckets[i].back().getY(), 2.f, sf::Color::White,
                                                  speed / 2, window);
            }
        } else {
            points_left.push_back(buckets[i].front());
            AnimationController::animatePoint(buckets[i].front().getX(), buckets[i].front().getY(), 2.f, sf::Color::Blue,
                                              speed / 2, window);
            points_right.push_back(buckets[i].back());
            AnimationController::animatePoint(buckets[i].back().getX(), buckets[i].back().getY(), 2.f, sf::Color::White,
                                              speed / 2, window);
        }
    }

    vector<vector<Point>> res;
    res.push_back(points_left);
    res.push_back(points_right);
    return res;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

double rotation_angle(Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    double angle = asin((ab * ab + bc * bc - ac * ac) / (2 * ab * bc));
    return angle;
}

bool is_rotation_right(Point a, Point b, Point c) {
    return !(b.getX() > a.getX() && b.getX() > c.getX());
}