//Lauryn Stanislaus

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
protected:
    string name;

public:
    
    Shape(string n);  
    virtual void Display() const = 0;  
    virtual ~Shape()= default; 
};

#endif

