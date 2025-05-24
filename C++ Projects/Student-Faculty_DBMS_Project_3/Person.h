//Lauryn Stanislaus 
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>


using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person();
    Person(const string& name, int id);
    
    virtual ~Person();
    virtual void display() const = 0;
    const string& getName() const;
    int getID() const;
};

#endif
