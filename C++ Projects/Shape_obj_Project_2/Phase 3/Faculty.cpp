//Soshi Jain Project 3 part 3 Faculty.cpp file
#include "Faculty.h"
#include <iostream>
#include <cassert>
using namespace std;

Faculty::Faculty() : Person(), department(""), title(""), salary(0) {}
Faculty::Faculty(const string& name, int id, const string& department,
                 const string& title, int salary)
    : Person(name, id), department(department), title(title), salary(salary) {
    assert(id > 0);
    assert(salary >= 0);
}
int Faculty::getID() const {
    return id;
}
const string& Faculty::getName() const {
    return name;
}
const string& Faculty::getDepartment() const {
    return department;
}

const string& Faculty::getTitle() const {
    return title;
}

int Faculty::getSalary() const {
    return salary;
}

void Faculty::setDepartment(const string& dept) {
    department = dept;
}

void Faculty::setTitle(const string& jobTitle) {
    title = jobTitle;
}

void Faculty::setSalary(int sal) {
    assert(sal >= 0);
    salary = sal;
}

void Faculty::display() const {
    cout << "FACULTY - ID: " << id
         << ", Name: " << name
         << ", Department: " << department
         << ", Title: " << title
         << ", Salary: " << salary << endl;
}
