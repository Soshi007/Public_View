//Soshi Jain
#include "DynamicArray.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>


int main(){
  Shape **a = new Shape*[3];
  a[0] = new Triangle(Edge(4),Edge(3),Point(2,3),90);
  a[1] = new Rectangle(Point(2,2),Edge(5),Edge(6));
  a[2] = new Circle(Point(3,3),10);
  DynamicArray<Shape*> shape1;
  shape1.add(a[0]);
  DynamicArray<Shape*> shape2(shape1);
  shape2.add(a[1]);
  DynamicArray<Shape*> shape3;
  shape3 = shape2;
  shape3.add(a[2]);
  cout<<"--------Shape 1--------"<<endl;
  for(int i=0;i<shape1.getNumElements();i++){
    shape1[i]->display();
  }
  cout<<"--------Shape 2--------"<<endl;
  for(int i=0;i<shape2.getNumElements();i++){
    shape2[i]->display();
  }
  cout<<"--------Shape 3--------"<<endl;
  for(int i=0;i<shape3.getNumElements();i++){
    shape3[i]->display();
  }
  cout<<"-----------------------"<<endl;
  return 0;
 }
