// Author: Eason Dong

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point();
    Point(double x, double y);

    void setX(double x);
    void setY(double y);

    double getX() const;
    double getY() const;

    void Display() const;
};

#endif // POINT_H