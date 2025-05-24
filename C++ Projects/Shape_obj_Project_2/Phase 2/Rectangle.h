//Lauryn Stanislaus
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"
#include "Edge.h"

class Rectangle : public Shape {
private:
    Point bottomLeft;
    Edge width;
    Edge height;

public:
    Rectangle();
    Rectangle(const Point& p, const Edge& w, const Edge& h);

    Point getBottomLeft() const;
    Edge getWidth() const;
    Edge getHeight() const;

    double Area() const;
    double Perimeter() const;
    void display() const;
};

#endif
