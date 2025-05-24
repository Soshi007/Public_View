//Obed James

#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"
#include <iostream>
#include <cassert>

using namespace std;

Circle::Circle() : Shape("Circle"), center(), radius(0) {} //Obed James

//Obed James
Circle::Circle(const Point& c, double r) : Shape("Circle"), center(c), radius(r) {// soshi jain- updated to pass
    //object to function by reference and added assertion for parameter value validation 04/21
    assert(radius >= 0 && "radius cant be negative");
} 

Point Circle::getCenter() const { //Obed James
    return center;
}

double Circle::getRadius() const { //Obed James
    return radius;
}

double Circle::Area() const { //Obed James
    return M_PI * radius * radius;
}

double Circle::Perimeter() const { //Obed James
    return 2 * M_PI * radius;
}

void Circle::display() const { //Obed James
    cout << "Shape: " << name << endl;
    cout << "Center Point: ";
    center.Display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << Area() << endl;       //eason dong - updated Display() to show area and perimeter
    cout << "Perimeter: " << Perimeter() << endl;
}
