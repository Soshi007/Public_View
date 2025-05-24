//phase 1 Author: Eason Dong

#include "Point.h"
#include <cassert> //soshi jain
Point::Point() : x(0), y(0) {} // Author: Eason Dong

Point::Point(double x, double y) : x(x), y(y) {} // Author: Eason Dong

void Point::setX(double x) {
  assert(x >= 0);//Soshi jain assertion added
  this->x = x; } // Author: Eason Dong
void Point::setY(double y) { 
   assert(y >= 0);//Soshi jain assertion added
  this->y = y; 
} // Author: Eason Dong

double Point::getX() const { return x; } // Author: Eason Dong
double Point::getY() const { return y; } // Author: Eason Dong

void Point::Display() const { // Author: Eason Dong
    cout << "Point(" << x << ", " << y << ")\n";
}
