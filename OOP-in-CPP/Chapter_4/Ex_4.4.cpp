#include <iostream>
using namespace std;

#define ERROR_INT "Error: Expected a positive integer for employee number."
#define ERROR_FLOAT "Error: Expected a positive number for salary."

struct employee {
    int number;
    float salary;
};

int main() {
    employee emp1, emp2, emp3;

    cout << "Enter data for employee 1:" << endl;
    cout << "Employee number: ";
    if (!(cin >> emp1.number) || emp1.number <= 0) {
        cout << ERROR_INT << endl;
        return 1;   // Error code for invalid integer input
    }
    cout << "Salary: ";
    if (!(cin >> emp1.salary) || emp1.salary < 0.0f) {
        cout << ERROR_FLOAT << endl;
        return 2;   // Error code for invalid float input
    }

    cout << "Enter data for employee 2:" << endl;
    cout << "Employee number: ";
    if (!(cin >> emp2.number) || emp2.number <= 0) {
        cout << ERROR_INT << endl;
        return 1;
    }
    cout << "Salary: ";
    if (!(cin >> emp2.salary) || emp2.salary < 0.0f) {
        cout << ERROR_FLOAT << endl;
        return 2;
    }

    cout << "Enter data for employee 3:" << endl;
    cout << "Employee number: ";
    if (!(cin >> emp3.number) || emp3.number <= 0) {
        cout << ERROR_INT << endl;
        return 1;
    }
    cout << "Salary: ";
    if (!(cin >> emp3.salary) || emp3.salary < 0.0f) {
        cout << ERROR_FLOAT << endl;
        return 2;
    }

    cout << "\nEmployee information:" << endl;
    cout << "Employee 1: Number = " << emp1.number << ", Salary = $" << emp1.salary << endl;
    cout << "Employee 2: Number = " << emp2.number << ", Salary = $" << emp2.salary << endl;
    cout << "Employee 3: Number = " << emp3.number << ", Salary = $" << emp3.salary << endl;

    return 0;
}

// TODO:
// 1) Move employee number and salary input into separate functions.
// 2) Validate that employee numbers are unique.
// 3) Remove #define (use string constants instead).