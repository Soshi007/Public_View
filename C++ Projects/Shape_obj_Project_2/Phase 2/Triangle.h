#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Edge.h"
#include "Point.h"
#include <cassert> //lauryn stanislaus

class Triangle : public Shape {
private:
    Edge a, b;
    Point vertex;
    double degree;

public:
    Triangle();
    Triangle(const Edge& edgeA, const Edge& edgeB, const Point& pt, double deg); //lauryn stanislaus- updated const reference
    void display() const override; 
    double Area() const override; // Lauryn Stanislaus- This is to calculate area and im using the right triangle method
    double Perimeter() const override; //Lauryn stanislaus- This is to calculate perimeter using pythagorean theorem
};

#endif
