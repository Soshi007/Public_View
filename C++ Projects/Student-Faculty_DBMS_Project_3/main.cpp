//Part 9 Main Menu UI Soshi Jain
#include <iostream>
#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include <limits>
using namespace std;

void displayMenu() {
    cout << "========== Academic Management System ==========\n";
    cout << "1. Add Student (Console)\n";
    cout << "2. Add Students from Text File\n";
    cout << "3. Add Students from CSV File\n";
    cout << "4. Add Faculty (Console)\n";
    cout << "5. Add Faculty from Text File\n";
    cout << "6. Add Faculty from CSV File\n";
    cout << "7. Display All Records\n";
    cout << "8. Search by ID\n";
    cout << "9. Update by ID\n";
    cout << "10. Delete by ID\n";
    cout << "11. Sort by ID\n";
    cout << "12. Sort by Name\n";
    cout << "13. Sort by GPA (Students Only)\n";
    cout << "14. Exit\n\n";
}

void addStudentFromConsole(LinkedList<Person*>& list);
void addStudentsFromTxt(const string& filename, LinkedList<Person*>& list);
void addStudentsFromCSV(const string& filename, LinkedList<Person*>& list);
void addFacultyFromConsole(LinkedList<Person*>& list);
void addFacultyFromTxt(const string& filename, LinkedList<Person*>& list);
void addFacultyFromCSV(const string& filename, LinkedList<Person*>& list);

int main() {
    LinkedList<Person*> database;
    int choice =0;

  
   do {
        displayMenu();

        string input;
        cout << "Enter your choice [1-14]: ";
        getline(cin, input);

        // Input validation
        bool valid = !input.empty();
        for (char c : input) {
            if (c < '0' || c > '9') {
                valid = false;
                break;
            }
        }

        if (valid) {
            choice = 0;
            for (char c : input)
                choice = choice * 10 + (c - '0');

            if (choice < 1 || choice > 14) {
                cout << "Choice out of range. Please enter a number between 1 and 14.\n\n";
                continue;
            }
        } else {
            cout << "Invalid input. Please enter digits only.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudentFromConsole(database);
                break;
            case 2: {
                string filename;
                cout << "Enter text file name: ";
                cin >> filename;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush buffer
                addStudentsFromTxt(filename, database);
                break;
            }
            case 3: {
                string filename;
                cout << "Enter CSV file name: ";
                cin >> filename;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addStudentsFromCSV(filename, database);
                break;
            }
            case 4:
                addFacultyFromConsole(database);
                break;
            case 5: {
                string filename;
                cout << "Enter text file name: ";
                cin >> filename;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addFacultyFromTxt(filename, database);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter CSV file name: ";
                cin >> filename;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addFacultyFromCSV(filename, database);
                break;
            }
            case 7:
                database.display();
                break;
            case 8: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Person* p = database.search(id);
                if (p) p->display();
                else cout << "Person not found.\n";
                break;
            }
            case 9: {
                int id;
                cout << "Enter ID to update: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                database.update(id);
                break;
            }
            case 10: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                database.remove(id);
                break;
            }
            case 11:
                database.sortByID();
                break;
            case 12:
                database.sortByName();
                break;
            case 13:
                database.sortByGPA();
                break;
            case 14:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << endl;

    } while (choice != 14);

    return 0;
}
