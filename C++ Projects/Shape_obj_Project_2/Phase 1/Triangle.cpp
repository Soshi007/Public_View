//Lauryn Stanislaus

#include "Triangle.h"

Triangle::Triangle() : Shape("Triangle"), a(0), b(0), vertex(0, 0), degree(0) {} //Lauryn Stanislaus

Triangle::Triangle(Edge edgeA, Edge edgeB, Point pt, double deg)   //Lauryn Stanislaus
    : Shape("Triangle"), a(edgeA), b(edgeB), vertex(pt), degree(deg) {}

void Triangle::Display() const { //Lauryn Stanislaus
    cout << "Name: " << name << endl;
    cout << "Length of Edge A: " << a.getLength() << endl;
    cout << "Length of Edge B: " << b.getLength() << endl;
    cout << "Coordinates of Vertex: (" << vertex.getX() << ", " << vertex.getY() << ")" << endl;
    cout << "Angle (in degrees): " << degree << endl;
}
