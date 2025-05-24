//Lauryn Stanislaus

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

using namespace std;

class Student : public Person {
private:
    string major;
    double gpa;

public:
    Student();
    Student(const string& name, int id, const string& major, double gpa);
    const string& getMajor() const;
    double getGPA() const;
    const string& getName() const;
    int getID() const;
    void setMajor(const string& major);
    void setGPA(double gpa);
    void display() const override;
};

#endif
