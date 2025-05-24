#include "DynamicArray.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Edge.h"
#include "Point.h"
using namespace std;
#include <fstream>
#include <cassert>
#include <string>
#include <iostream>


//Lauryn stanislaus added function(MaxArea) which returns the maximum area of shape

//Soshi Jain
DynamicArray<Shape*> CreateDynamicShapeArray(const string& filename) { 
    assert(!filename.empty());

    ifstream in(filename);
    assert(in.is_open());

    int n = 0;
    in >> n;
    assert(n > 0);

    DynamicArray<Shape*> arr;

    for (int k = 0; k < n; ++k) {
        string type;
        in >> type;

        if (type == "Triangle") {
            double a, b, angle;
            char p1, comma, p2;
            int x, y;

            in >> a >> b >> p1 >> x >> comma >> y >> p2 >> angle;
            assert(p1 == '(' && comma == ',' && p2 == ')');

            arr.add(new Triangle(a, b, Point(x, y), angle));
        }
        else if (type == "Rectangle") {
            char p1, comma, p2;
            int x, y;
            double l, w;

            in >> p1 >> x >> comma >> y >> p2 >> l >> w;
            assert(p1 == '(' && comma == ',' && p2 == ')');

            arr.add(new Rectangle(Point(x, y), l, w));
        }
        else if (type == "Circle") {
            char p1, comma, p2;
            int x, y;
            double r;

            in >> p1 >> x >> comma >> y >> p2 >> r;
            assert(p1 == '(' && comma == ',' && p2 == ')');

            arr.add(new Circle(Point(x, y), r));
        }
        else {
            assert(false && "Unknown shape type");
        }
    }

    return arr;
}

//Lauryn stanislaus 

Shape* MaxArea(DynamicArray<Shape*>& shapes) {
    assert(shapes.getNumElements() > 0 && "The shape array must not be empty.");

    Shape* maxShape = shapes[0];
    double maxArea = maxShape->Area();

    for (int i = 1; i < shapes.getNumElements(); ++i) {
        double area = shapes[i]->Area();
        if (area > maxArea) {
            maxArea = area;
            maxShape = shapes[i];
        }
    }

    return maxShape;
}

DynamicArray<Shape*> CreateDynamicShapeArray(const string& filename);

int main() {
    string filename;

    while (true) {
        cout << "Enter the filename (or 'stop' to quit): ";
        cin >> filename;

        if (filename == "stop") {
            break;
        }

        ifstream in(filename);
        if (!in.is_open()) {
            cout<< "Error: Could not open file or does not exist: " <<filename<< ". Please try again.\n";
            continue;
        }
        in.close();

        DynamicArray<Shape*> shapes = CreateDynamicShapeArray(filename);

        if (shapes.getNumElements() == 0) {
            cout << "No shapes found.\n";
            continue;
        }

        cout << "\n---------- All Shapes ----------\n";
        for (int i = 0; i < shapes.getNumElements(); ++i) {
            int counter= i+1
            cout << "-------- Shape "<<counter<<" --------\n";
            shapes[i]->display();
            
        }

        Shape* largest = MaxArea(shapes);
        if (largest) {
            cout << "-------- Shape with Max Area --------\n";
            largest->display();
        }

        for (int i = 0; i < shapes.getNumElements(); ++i) {
            delete shapes[i];
        }
    }

    cout << "Program ended.\n";
    return 0;
}


//Comment by team lead- Eason's work will not be used due to no colaboration or communication with team in time.
//Just sending one email to me stating that part 14 will be done by you(eason) and doing it few hours before submission deadline does not work out with other team member due to debugging and program trial runs, it is not enough colaboration and communication from eason's end.
/*
    // Eason Dong - line: 111-151
    string filename;

    while (true) {
        cout << "Enter the name of the shape file (or 'stop' to exit): ";
        getline(cin, filename);

        if (filename == "stop") break;

        int size = 0;
        Shape** shapeArray = CreateDynamicShapeArray(filename, size);

        if (!shapeArray || size == 0) {
            cout << "No shapes loaded or file not found.\n";
            continue;
        }

        cout << "\nLoaded Shapes:\n";
        for (int i = 0; i < size; ++i) {
            shapeArray[i]->Display();
            cout << "Area: " << shapeArray[i]->GetArea() << "\n\n";
        }

        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (shapeArray[i]->GetArea() > shapeArray[maxIndex]->GetArea()) {
                maxIndex = i;
            }
        }

        cout << "Shape with the Maximum Area:\n";
        shapeArray[maxIndex]->Display();
        cout << "Area: " << shapeArray[maxIndex]->GetArea() << "\n";

        
        for (int i = 0; i < size; ++i) {
            delete shapeArray[i];
        }
        delete[] shapeArray;
    }
    cout << "Program ended.\n";
    
    return 0;
}
*/









//phase 2
/*
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
*/























































