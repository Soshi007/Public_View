// Author: Eason Dong

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
using namespace std;

class Edge {
private:
    double length;

public:
    Edge();
    Edge(double length);

    void setLength(double length);
    double getLength() const;

    void Display() const;
};

#endif // EDGE_H