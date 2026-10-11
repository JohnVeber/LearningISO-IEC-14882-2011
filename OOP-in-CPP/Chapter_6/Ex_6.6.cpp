#include <iostream>
#include <iomanip>
using namespace std;

/*    The 'unknown' value is added deliberately as the first enumerator.
      It represents the "not set" state, because C++ enumerations have no
      built-in "empty" value. The constructor of class "Employee" would
      otherwise have to assign a real position (e.g., laborer) before any
      data is entered, which would be misleading.                      */
enum etype { unknown, laborer, secretary, manager, accountant, executive, researcher };

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date() : month(0), day(0), year(0) { } // Default constructor: initializes all fields to zero.

    // Method for reading a date from the user in MM/DD/YY format.
    void getdate() {
        char slash;

        while (true) { // Repeats the request until valid input is entered.
            cout << "Enter hire date (MM/DD/YY): ";

            cin >> month >> slash;
            if (!cin || slash != '/') {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: use MM/DD/YY format (e.g., 12/31/02). Try again." << endl;
                continue;
            }

            cin >> day >> slash;
            if (!cin || slash != '/') {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: use MM/DD/YY format (e.g., 12/31/02). Try again." << endl;
                continue;
            }

            cin >> year;
            if (!cin) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: invalid year. Try again." << endl;
                continue;
            }

            if (month < 1 || month > 12) {
                cout << "Error: month must be between 1 and 12. Try again." << endl;
                continue;
            }
            if (day < 1 || day > 31) {
                cout << "Error: day must be between 1 and 31. Try again." << endl;
                continue;
            }
            if (year < 0 || year > 99) {
                cout << "Error: year must be between 0 and 99. Try again." << endl;
                continue;
            }

            break;
        }
    }

    // Constant method: prints the date in MM/DD/YY format with leading zeros.
    void showdate() const {
        cout << setfill('0')
             << setw(2) << month << "/"
             << setw(2) << day   << "/"
             << setw(2) << year
             << setfill(' ');
    }
};

class Employee {
private:
    int employeeId;
    float employeeSalary;
    Date hireDate;
    etype position;

public:
    // Position is set to 'unknown' deliberately: see the comment above 'enum etype'.
    Employee() : employeeId(0), employeeSalary(0.0f), hireDate(), position(unknown) { } // Default constructor: initializes all fields to zero.

    // Method for setting the values from input.
    void getemploy() {
        // Employee ID.
        while (true) {
            cout << "Enter the employee's Id: ";
            cin >> employeeId;
            if (!cin || employeeId <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: expected a positive integer. Try again." << endl;
                continue;
            }
            break;
        }

        // Employee salary.
        while (true) {
            cout << "Enter the employee's salary ($): ";
            cin >> employeeSalary;
            if (!cin || employeeSalary < 0.0f) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: expected a non-negative number. Try again." << endl;
                continue;
            }
            break;
        }

        // Hire date.
        hireDate.getdate();

        // Position, entered by the first letter.
        while (true) {
            char firstLetter;
            cout << "Enter the first letter of the employee's position" << endl;
            cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
            cin >> firstLetter;

            switch (firstLetter) {
                case 'l': position = laborer;    break;
                case 's': position = secretary;  break;
                case 'm': position = manager;    break;
                case 'a': position = accountant; break;
                case 'e': position = executive;  break;
                case 'r': position = researcher; break;
                default:
                    cout << "Error: invalid first letter. Try again." << endl;
                    continue; // Back to the top of the while loop.
            }
            break;
        }
    }

    // Constant method: prints the values to the screen.
    void putemploy() const {
        cout << "ID: " << employeeId << endl;
        cout << "Salary: " << fixed << setprecision(2) << employeeSalary << "$" << endl;
        cout.unsetf(ios::fixed); // Return format back.
        cout << setprecision(6); // Return precision back to default (6).
        cout << "Hire date: "; hireDate.showdate(); cout << endl;
        cout << "Position: ";

        switch (position) {
            case unknown:    cout << "not set";    break;
            case laborer:    cout << "laborer";    break;
            case secretary:  cout << "secretary";  break;
            case manager:    cout << "manager";    break;
            case accountant: cout << "accountant"; break;
            case executive:  cout << "executive";  break;
            case researcher: cout << "researcher"; break;
        }
        cout << endl;
    }
};

int main() {
    Employee e1, e2, e3;

    cout << "\nEmployee 1 data:" << endl;
    e1.getemploy();

    cout << "\nEmployee 2 data:" << endl;
    e2.getemploy();

    cout << "\nEmployee 3 data:" << endl;
    e3.getemploy();

    cout << "\n--- Employee information ---" << endl;

    cout << "\nEmployee 1:" << endl;
    e1.putemploy();

    cout << "\nEmployee 2:" << endl;
    e2.putemploy();

    cout << "\nEmployee 3:" << endl;
    e3.putemploy();

    return 0;
}

// TODO:
// 1) Enforce uniqueness of the employee ID at object creation time.