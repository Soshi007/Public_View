#include "Shape.h"
#include <cassert>

Shape::Shape(const string& n) : name(n) {
   assert(!n.empty() && "Shape name cannot be blank");
} //Lauryn stanislaus- const reference and assertion
