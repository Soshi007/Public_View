//Obed James 

#include "Rectangle.h"
#include <iostream>
#include <cassert>

using namespace std;

Rectangle::Rectangle() : Shape("Rectangle"), bottomLeft(), width(0), height(0) {} //Obed James

Rectangle::Rectangle(const Point& p, const Edge& w, const Edge& h) //Obed James p1// soshi jain- i updated to pass by reference 
//and added assertion to validate parameter values 04/21.
    : Shape("Rectangle"), bottomLeft(p), width(w), height(h) {
    assert(w.getLength() >= 0 && "Width to be non negative value");
    assert(h.getLength() >= 0 && "Height to be non negative value");  
    }

Point Rectangle::getBottomLeft() const { //Obed James
    return bottomLeft;
}

Edge Rectangle::getWidth() const { //Obed James
    return width;
}

Edge Rectangle::getHeight() const {//Obed James
    return height;
}

double Rectangle::Area() const {//Obed James
    return width.getLength() * height.getLength();
}

double Rectangle::Perimeter() const {//Obed James
    return 2 * (width.getLength() + height.getLength());
}

void Rectangle::display() const {//Obed James
    cout << "Rectangle - Bottom Left: ";
    bottomLeft.Display();
    cout << "Width: " << width.getLength() << endl
         << "Height: " << height.getLength() << endl
         << "Area: " << Area() << endl              //eason dong - updated Display() to show area and perimeter 
         << "Perimeter: " << Perimeter() << endl;
}
