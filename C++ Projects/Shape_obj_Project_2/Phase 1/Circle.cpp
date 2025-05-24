//Obed James

#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() : Shape("Circle"), center(), radius(0) {} //Obed James

Circle::Circle(Point p, double r) : Shape("Circle"), center(p), radius(r) {} //Obed James

Point Circle::getCenter() const { //Obed James
    return center;
}

double Circle::getRadius() const { //Obed James
    return radius;
}

double Circle::area() const { //Obed James
    return M_PI * radius * radius;
}

double Circle::perimeter() const { //Obed James
    return 2 * M_PI * radius;
}

void Circle::Display() const { //Obed James
    cout << "Shape: " << name << endl;
    cout << "Center Point: ";
    center.Display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}