#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(const string& n);  // Lauryn stanislaus- pass string by const reference
    virtual void display() const = 0;
    virtual double Area() const = 0;        // Lauryn Stanislaus - pure virtual Area function
    virtual double Perimeter() const = 0;   // Lauryn Stanislaus - pure virtual Perimeter function
    virtual ~Shape() = default;             // Lauryn Stanislaus - default destructor
};

#endif
