//Soshi Jain ET580 Project 3 part 3 Faculty header file
#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>

using namespace std;

class Faculty : public Person {
private:
    string department;
    string title;
    int salary;
public:
    Faculty();
    Faculty(const string& name, int id, const string& department,
            const string& title, int salary);

    const string& getDepartment() const;
    const string& getTitle() const;
    const string& getName() const;
    int getSalary() const;
    int getID() const;

    void setDepartment(const string& department);
    void setTitle(const string& title);
    void setSalary(int salary);
    void display() const override;
};

#endif 
