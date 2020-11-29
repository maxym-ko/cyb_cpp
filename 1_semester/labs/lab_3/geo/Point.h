//
// Created by maxym_ko on 11/25/20.
//

#ifndef LAB_3_POINT_H
#define LAB_3_POINT_H


class Point {
private:
    int x, y;
    static int max_x, max_y;
public:
    Point();

    Point(int x, int y);

    int getX() const;

    int getY() const;

    static int get_max_x();

    static void set_max_x(int x);

    static int get_max_y();

    static void set_max_y(int y);

    friend std::ostream &operator<<(std::ostream &os, Point point);

    bool operator==(const Point& point) const;

    bool operator!=(const Point& point) const;
};


#endif //LAB_3_POINT_H
