//Lauryn Stanislaus

#include "Triangle.h"
#include <cmath> 
#include <cassert>  // Lauryn stanislaus- added assertions

Triangle::Triangle() : Shape("Triangle"), a(0), b(0), vertex(0, 0), degree(0) {
    assert(a.getLength() > 0 && "Edge A length needs to be positive");
    assert(b.getLength() > 0 && "Edge B length needs to be positive");
    assert(degree >= 0 && degree <= 180 && "Angle needs to be between 0 and 180 degrees");
}

Triangle::Triangle(const Edge& edgeA, const Edge& edgeB, const Point& pt, double deg)
    : Shape("Triangle"), a(edgeA), b(edgeB), vertex(pt), degree(deg) {
    
    assert(a.getLength() > 0 && "Edge A length needs to be positive");
    assert(b.getLength() > 0 && "Edge B length needs be positive");
    assert(degree >= 0 && degree <= 180 && "Angle needs to be between 0 and 180 degrees");
    }


double Triangle::Area() const {
    double aLength = a.getLength(); //eason dong
    double bLength = b.getLength(); //eason dong
    double radians = degree * M_PI / 180.0;
    return 0.5 * aLength * bLength * sin(radians); //eason dong
}

double Triangle::Perimeter() const {//eason dong
    double aLength = a.getLength();
    double bLength = b.getLength();
    double radians = degree * M_PI / 180.0;
    double cLength = sqrt(aLength * aLength + bLength * bLength - 2 * aLength * bLength * cos(radians)); //eason dong
    return aLength + bLength + cLength;
    
}

void Triangle::display() const { //Lauryn Stanislaus
    cout << "Name: " << name << endl;
    cout << "Length of Edge A: " << a.getLength() << endl;
    cout << "Length of Edge B: " << b.getLength() << endl;
    cout << "Coordinates of Vertex: (" << vertex.getX() << ", " << vertex.getY() << ")" << endl;
    cout << "Angle (in degrees): " << degree << endl;
    cout << "Perimeter: " << Perimeter() << endl;    //eason dong
    cout << "Area: " << Area() << endl;  
}
