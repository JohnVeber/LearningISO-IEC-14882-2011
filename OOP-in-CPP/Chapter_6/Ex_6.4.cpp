#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    int employeeId;
    float employeeSalary;

public:
    Employee() : employeeId(0), employeeSalary(0.0f) { } // Default constructor: initializes all fields to zero.

    // Method for setting the values from input.
    void setEmployeeData() {
        cout << "Enter the employee's Id: ";
        while (!(cin >> employeeId) || employeeId <= 0) {
            cin.clear();             // Reset the error flag on cin.
            cin.ignore(10000, '\n'); // Discard the invalid input.
            cout << "Error: expected a positive integer. Try again: ";
        }

        cout << "Enter the employee's salary ($): ";
        while (!(cin >> employeeSalary) || employeeSalary < 0.0f) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: expected a non-negative number. Try again: ";
        }
    }

    // Method for printing the values to the screen.
    void printEmployeeData() const {
        cout << "ID: " << employeeId << "." << endl;
        cout << "Salary: " << fixed << setprecision(2) << employeeSalary << "$." << endl;
    }
};

int main() {
    Employee e1, e2, e3;

    e1.setEmployeeData();
    e2.setEmployeeData();
    e3.setEmployeeData();

    cout << "\nEmployee 1:" << endl;
    e1.printEmployeeData();

    cout << "\nEmployee 2:" << endl;
    e2.printEmployeeData();

    cout << "\nEmployee 3:" << endl;
    e3.printEmployeeData();

    return 0;
}

// TODO:
// 1) Enforce uniqueness of the employee ID at object creation time.