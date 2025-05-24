//Lauryn Stanislaus 

#include "Person.h"
#include <cassert>
using namespace std;

Person::Person() : name(""), id(0) {}

Person::Person(const string& name, int id) : name(name), id(id) {
    assert(id >= 0);
}

Person::~Person() {}

const string& Person::getName() const {
    return name;
}

int Person::getID() const {
    return id;
}
