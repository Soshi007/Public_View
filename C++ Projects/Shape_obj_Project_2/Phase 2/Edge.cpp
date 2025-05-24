// Author: Eason Dong

#include "Edge.h"
#include <cassert>

Edge::Edge() : length(0) {} // Author: Eason Dong

Edge::Edge(double length) : length(length) {} // Author: Eason Dong

void Edge::setLength(double length) { 
  assert(length >= 0);
  this->length = length; } // Author: Eason Dong

double Edge::getLength() const { return length; } // Author: Eason Dong

void Edge::Display() const { // Author: Eason Dong
    cout << "Edge Length: " << length << "\n";
}
