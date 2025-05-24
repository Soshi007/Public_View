//Part5: Ongshi Dugar
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include "Person.h"
#include <string>
using namespace std;

template <typename T>
class LinkedList {
private:
    ListNode <Person*>* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(Person* data);
    void display() const;
    Person* search(int id) const;
    Person* search(const string& firstName, const string& lastName) const;
    void update(int id);
    void remove(int id);

//Part 6 Lauryn Stanislaus

    void addStudentFromConsole(LinkedList &list);
    void addStudentsFromTxt(string& filename, LinkedList& list);
    void addStudentsFromCSV(string& filename, LinkedList& list);
//Part 7 Ongshi Dugar
    void addFacultyFromConsole(LinkedList& list);
    void addFacultyFromTxt(string& filename, LinkedList& list);
    void addFacultyFromCSV(string& filename, LinkedList& list);



//Part 8 sorting, Soshi Jain{
    void sortByID();
    void sortByName();
    void sortByGPA();
//}
};
#endif
