//Obed James

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle();
    Circle(Point, double);

    Point getCenter() const;
    double getRadius() const;

    double area() const;
    double perimeter() const;
    void Display() const;
};

#endif