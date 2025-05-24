//Obed James

#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle() : Shape("Rectangle"), bottomLeft(), width(0), height(0) {} //Obed James

Rectangle::Rectangle(Point p, Edge w, Edge h) //Obed James
    : Shape("Rectangle"), bottomLeft(p), width(w), height(h) {}

Point Rectangle::getBottomLeft() const { //Obed James
    return bottomLeft;
}

Edge Rectangle::getWidth() const { //Obed James
    return width;
}

Edge Rectangle::getHeight() const {//Obed James
    return height;
}

double Rectangle::area() const {//Obed James
    return width.getLength() * height.getLength();
}

double Rectangle::perimeter() const {//Obed James
    return 2 * (width.getLength() + height.getLength());
}

void Rectangle::Display() const {//Obed James
    cout << "Rectangle - Bottom Left: ";
    bottomLeft.Display();
    cout << "Width: " << width.getLength() << endl
         << "Height: " << height.getLength() << endl
         << "Area: " << area() << endl
         << "Perimeter: " << perimeter() << endl;
}