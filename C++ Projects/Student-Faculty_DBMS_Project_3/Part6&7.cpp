#include <iostream>
using namespace std;

void addStudentFromConsole(LinkedList<Person*>& list) {
    int id;
    string name, major;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> ws; getline(cin, name);
    cout << "Enter Major: ";
    getline(cin, major);
    cout << "Enter GPA: ";
    cin >> gpa;

    list.insert(new Student(id, name, major, gpa));
}

void addStudentsFromTxt(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    int id;
    string name, major;
    double gpa;

    while (file >> id >> name >> major >> gpa) {
        list.insert(new Student(id, name, major, gpa));
    }
    file.close();
}

void addStudentsFromCSV(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, major, gpaStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, major, ',');
        getline(ss, gpaStr, ',');

        int id = stoi(idStr);
        double gpa = stod(gpaStr);
        list.insert(new Student(id, name, major, gpa));
    }
    file.close();
}

void addFacultyFromConsole(LinkedList<Person*>& list) {
    int id;
    string name, department, title;
    double salary;

    cout << "Enter Faculty ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> ws; getline(cin, name);
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Salary: ";
    cin >> salary;

    list.insert(new Faculty(id, name, department, title, salary));
}

void addFacultyFromTxt(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    int id;
    string name, department, title;
    double salary;

    while (file >> id >> name >> department >> title >> salary) {
        list.insert(new Faculty(id, name, department, title, salary));
    }
    file.close();
}

void addFacultyFromCSV(const string& filename, LinkedList<Person*>& list) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, department, title, salaryStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, department, ',');
        getline(ss, title, ',');
        getline(ss, salaryStr, ',');

        int id = stoi(idStr);
        double salary = stod(salaryStr);
        list.insert(new Faculty(id, name, department, title, salary));
    }
    file.close();
}