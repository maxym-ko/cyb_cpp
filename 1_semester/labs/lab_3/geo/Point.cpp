//
// Created by maxym_ko on 11/25/20.
//

#include <cstdlib>
#include <iostream>
#include "Point.h"

using namespace std;

int Point::max_y = 0;
int Point::max_x = 0;

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() {
    x = (rand() % Point::max_x) + 1;
    y = (rand() % Point::max_y) + 1;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::get_max_x() {
    return max_x;
}

void Point::set_max_x(int x) {
    srand(time(nullptr));
    max_x = x;
}

int Point::get_max_y() {
    return max_y;
}

void Point::set_max_y(int y) {
    srand(time(nullptr));
    max_y = y;
}

std::ostream& operator<<(std::ostream& os, Point point)
{
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

bool Point::operator==(const Point &point) const {
    return x == point.x && y == point.y;
}

bool Point::operator!=(const Point &point) const {
    return x != point.x || y != point.y;
}
