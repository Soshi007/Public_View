//Lauryn Stanislaus

#include "Student.h"
#include <iostream>
#include <cassert>
using namespace std; 

Student::Student() : Person(), major(""), gpa(0.0) {}

Student::Student(const string& name, int id, const string& major, double gpa)
    : Person(name, id), major(major), gpa(gpa) {
   // assert(gpa >= 0.0 && gpa <= 4.0);
}

const string& Student::getMajor() const {
    return major;
}

double Student::getGPA() const {
    return gpa;
}

const string& Student::getName() const {
    return name;
}

int Student::getID() const {
    return id;
}

void Student::setMajor(const string& major) {
    this->major = major;
}

void Student::setGPA(double gpa) {
    assert(gpa >= 0.0 && gpa <= 4.0);
    this->gpa = gpa;
}

void Student::display() const {
    cout << "Student - ID: " << id
         << ", Name: " << name
         << ", Major: " << major
         << ", GPA: " << gpa << endl;
}

