//Part5: Ongshi Dugar
#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

template<>
LinkedList<Person*>::LinkedList() : head(nullptr) {}

template<>
LinkedList<Person*>::~LinkedList() {
    ListNode<Person*>* current = head;
    while (current) {
        ListNode<Person*>* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}

template<>
void LinkedList<Person*>::insert(Person* data) {
    Person** dataPtr = new Person*(data);
    ListNode<Person*>* newNode = new ListNode<Person*>(dataPtr);
    if (!head) {
        head = newNode;
    } else {
        ListNode<Person*>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<>
void LinkedList<Person*>::display() const {
    if(!head){
        cout<< "Nothing in database, please add.\n";
        return;
    }
    cout<< "\n----- DATABASE -----\n";
    ListNode<Person*>* current = head;
    while (current) {
        if (current->data && *current->data){
        (*current->data)->display();  
        }
        current = current->next;
    }
}

template<>
Person* LinkedList<Person*>::search(int id) const {
    ListNode<Person*>* current = head;
    while (current) {
        Student* s = dynamic_cast<Student*>(*current->data);
        if (s && s->getID() == id) return s;

        Faculty* f = dynamic_cast<Faculty*>(*current->data);
        if (f && f->getID() == id) return f;

        current = current->next;
    }
    return nullptr;
}

template<>
Person* LinkedList<Person*>::search(const string& firstName, const string& lastName) const {
    ListNode<Person*>* current = head;
    while (current) {
        Student* s = dynamic_cast<Student*>(*current->data);
        if (s) {
            istringstream iss(s->getName());
            string first, last;
            iss >> first >> last;
            if (first == firstName && last == lastName)
                return s;
        }

        Faculty* f = dynamic_cast<Faculty*>(*current->data);
        if (f) {
            istringstream iss(f->getName());
            string first, last;
            iss >> first >> last;
            if (first == firstName && last == lastName)
                return f;
        }

        current = current->next;
    }
    return nullptr;
}

template<>
void LinkedList<Person*>::update(int id) {
    Person* person = search(id);
    if (!person) {
        cout << "Person with ID " << id << " not found.\n";
        return;
    }

    Student* s = dynamic_cast<Student*>(person);
    if (s) {
        string major;
        double gpa;
        cout << "Enter new major: ";
        getline(cin, major);
        cout << "Enter new GPA: ";
        cin >> gpa;
        cin.ignore();
        s->setMajor(major);
        s->setGPA(gpa);
        return;
    }

    Faculty* f = dynamic_cast<Faculty*>(person);
    if (f) {
        string dept, title;
        int salary;
        cout << "Enter new department: ";
        getline(cin, dept);
        cout << "Enter new title: ";
        getline(cin, title);
        cout << "Enter new salary: ";
        cin >> salary;
        cin.ignore();
        f->setDepartment(dept);
        f->setTitle(title);
        f->setSalary(salary);
        return;
    }

    cout << "Unknown type.\n";
}

template<>
void LinkedList<Person*>::remove(int id) {
    ListNode<Person*>* current = head;
    ListNode<Person*>* previous = nullptr;

    while (current) {
        Person* p = *current->data;
        Student* s = dynamic_cast<Student*>(p);
        Faculty* f = dynamic_cast<Faculty*>(p);

        int currentID = -1;
        if (s) currentID = s->getID();
        else if (f) currentID = f->getID();

        if (currentID == id) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current->data;
            delete current;
            cout << "Removed person with ID " << id << endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Person with ID " << id << " not found.\n";
}

//Lauryn stanislaus
void addStudentFromConsole(LinkedList<Person*>& list) {
    int id;
    string name, major;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter Major: ";
    getline(cin, major);

    cout << "Enter GPA: ";
    cin >> gpa;

    list.insert(new Student(name, id, major, gpa));
    cout << "Student added from console.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//Lauryn stanislaus
void addStudentsFromTxt(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, major, gpaStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, major, ',');
        getline(ss, gpaStr, ',');

        if (idStr.empty() || name.empty() || major.empty() || gpaStr.empty()) continue;

        int id = stoi(idStr);
        double gpa = stod(gpaStr);

        list.insert(new Student(name, id, major, gpa));
    }

    file.close();
    cout << "Finished reading students from TXT (CSV-style) file.\n";
}
//Lauryn stanislaus
void addStudentsFromCSV(const string& filename, LinkedList<Person*>& list) {
    addStudentsFromTxt(filename, list);
}


//Ongshi Dugar
void addFacultyFromConsole(LinkedList<Person*>& list) {
    int id;
    string name, department, title;
    double salary;

    cout << "Enter Faculty ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Salary: ";
    cin >> salary;

    list.insert(new Faculty(name, id, department, title, salary));
    cout << "Faculty added from console.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//Ongshi Dugar
void addFacultyFromTxt(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file \"" << filename << "\".\n" <<endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, department, title, salaryStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, department, ',');
        getline(ss, title, ',');
        getline(ss, salaryStr, ',');

        if (idStr.empty() || name.empty() || department.empty() || title.empty() || salaryStr.empty()) continue;

        try{  
        int id = stoi(idStr);
        double salary = stod(salaryStr);
        list.insert(new Faculty(name, id, department, title, salary));
    } catch (const exception& e) {
        cerr << "Warning: Skipping malformed line. \n";
    }
    }
    file.close();
    cout << "Finished reading faculty from TXT (CSV-style) file.\n";
}
//Ongshi Dugar
void addFacultyFromCSV(const string& filename, LinkedList<Person*>& list) {
    addFacultyFromTxt(filename, list);
}








//Part 8 sorting, Soshi Jain {
template<>
void LinkedList<Person*>::sortByID() {
    std::vector<Person*> people;
    ListNode<Person*>* cuR = head;

    while (cuR) {
        people.push_back(*cuR->data);
        cuR = cuR->next;
    }

    std::sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getID() < b->getID();
    });

    cuR = head;
    for (Person* p : people) {
        *(cuR->data) = p;
        cuR = cuR->next;
    }
}
template<>
void LinkedList<Person*>::sortByName() {
    std::vector<Person*> people;
    ListNode<Person*>* cuR = head;

    while (cuR) {
        people.push_back(*cuR->data);
        cuR = cuR->next;
    }

    std::sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getName() < b->getName();
    });

    cuR = head;
    for (Person* p : people) {
        *(cuR->data) = p;
        cuR = cuR->next;
    }
}
template<>
void LinkedList<Person*>::sortByGPA() {
    std::vector<Person*> people;
    ListNode<Person*>* cuR = head;

    while (cuR) {
        people.push_back(*cuR->data);
        cuR = cuR->next;
    }

    std::sort(people.begin(), people.end(), [](Person* a, Person* b) {
        Student* sa = dynamic_cast<Student*>(a);
        Student* sb = dynamic_cast<Student*>(b);
        double gpaA = sa ? sa->getGPA() : 0.0;
        double gpaB = sb ? sb->getGPA() : 0.0;
        return gpaA > gpaB; 
    });

    cuR = head;
    for (Person* p : people) {
        *(cuR->data) = p;
        cuR = cuR->next;
    }
}



//}
