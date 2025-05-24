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
    Circle(const Point& c, double r);

    Point getCenter() const;
    double getRadius() const;

    double Area() const override; //Lauryn Stanislaus- I added override for area, perimeter, and display
    double Perimeter() const override; // lauryn stanislaus 
    void display() const override; // lauryn stanislaus 
};

#endif
