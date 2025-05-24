//Obed James

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"
#include "Edge.h"
using namespace std;

class Rectangle : public Shape {
private:
    Point bottomLeft;
    Edge width;
    Edge height;

public:
    Rectangle();
    Rectangle(Point, Edge, Edge);

    Point getBottomLeft() const;
    Edge getWidth() const;
    Edge getHeight() const;

    double area() const;
    double perimeter() const;
    void Display() const;
};

#endif