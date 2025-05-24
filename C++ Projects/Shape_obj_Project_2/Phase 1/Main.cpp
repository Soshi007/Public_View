//SOshi Jain
#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;

int main(){ //Soshi Jain
    Shape **a = new Shape*[3];
    a[0] = new Triangle(Edge(4),Edge(3),Point(2,3),90);
    a[1] = new Rectangle(Point(2,2),Edge(5),Edge(6));
    a[2] = new Circle(Point(3,3),10);
    for(int i=0;i<3;i++) {
    a[i]-> Display();
    cout<<endl;
    }
    return 0;
   }