//Lauryn Stanislaus 

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Edge.h"
#include "Point.h"
#include <iostream>
using namespace std;

class Triangle : public Shape {
private:
    Edge a, b;
    Point vertex;
    double degree;

public:
    Triangle();
    Triangle(Edge edgeA, Edge edgeB, Point pt, double deg);
    void Display() const override;
};

#endif 
