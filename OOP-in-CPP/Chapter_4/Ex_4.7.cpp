#include <iostream>
#include <iomanip>
using namespace std;

// Enumeration from Exercise 6
enum etype { laborer, secretary, manager, accountant, executive, researcher };

// Structure from Exercise 5
struct date {
    int day;
    int month;
    int year;
};

// Structure from Exercise 4, extended with position and hire date
struct employee {
    int number;
    float salary;
    etype position;
    date hire_date;
};

int main() {
    employee emp1, emp2, emp3; // Declared 3 variables of type "employee"
    char first_letter;
    char slash1, slash2;



    /*---------------------------------------- Employee 1 ----------------------------------------*/
    cout << "\nEnter data for employee 1:" << endl;

    cout << "Employee number: ";
    if (!(cin >> emp1.number) || emp1.number < 0) {
        cout << "Error: Expected a positive integer for employee number." << endl;
        return 1;
    }

    cout << "Salary: ";
    if (!(cin >> emp1.salary) || emp1.salary < 0) {
        cout << "Error: Expected a positive number for salary." << endl;
        return 2;
    }

    cout << "Enter the first letter of the position" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;

    switch (first_letter) {
        case 'l': emp1.position = laborer; break;
        case 's': emp1.position = secretary; break;
        case 'm': emp1.position = manager; break;
        case 'a': emp1.position = accountant; break;
        case 'e': emp1.position = executive; break;
        case 'r': emp1.position = researcher; break;
        default:{
            cout << "Error: Invalid first letter." << endl;
            return 3;
        }
    }

    cout << "Enter hire date (dd/mm/yyyy): ";
    cin >> emp1.hire_date.day >> slash1 >> emp1.hire_date.month >> slash2 >> emp1.hire_date.year;

    if (slash1 != '/' || slash2 != '/') {
        cout << "Error: Invalid date format. Please use dd/mm/yyyy." << endl;
        return 4;
    }
    if (emp1.hire_date.day < 1 || emp1.hire_date.day > 31) {
        cout << "Error: Day must be between 1 and 31." << endl;
        return 5;
    }
    if (emp1.hire_date.month < 1 || emp1.hire_date.month > 12) {
        cout << "Error: Month must be between 1 and 12." << endl;
        return 6;
    }
    if (emp1.hire_date.year < 0 || emp1.hire_date.year > 9999) {
        cout << "Error: Year must be between 0 and 9999." << endl;
        return 7;
    }



    /*---------------------------------------- Employee 2 ----------------------------------------*/
    cout << "\nEnter data for employee 2:" << endl;

    cout << "Employee number: ";
    if (!(cin >> emp2.number) || emp2.number < 0) {
        cout << "Error: Expected a positive integer for employee number." << endl;
        return 1;
    }

    cout << "Salary: ";
    if (!(cin >> emp2.salary) || emp2.salary < 0) {
        cout << "Error: Expected a positive number for salary." << endl;
        return 2;
    }

    cout << "Enter the first letter of the position" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;

    switch (first_letter) {
        case 'l': emp2.position = laborer; break;
        case 's': emp2.position = secretary; break;
        case 'm': emp2.position = manager; break;
        case 'a': emp2.position = accountant; break;
        case 'e': emp2.position = executive; break;
        case 'r': emp2.position = researcher; break;
        default:{
            cout << "Error: Invalid first letter." << endl;
            return 3;
        }
    }

    cout << "Enter hire date (dd/mm/yyyy): ";
    cin >> emp2.hire_date.day >> slash1 >> emp2.hire_date.month >> slash2 >> emp2.hire_date.year;

    if (slash1 != '/' || slash2 != '/') {
        cout << "Error: Invalid date format. Please use dd/mm/yyyy." << endl;
        return 4;
    }
    if (emp2.hire_date.day < 1 || emp2.hire_date.day > 31) {
        cout << "Error: Day must be between 1 and 31." << endl;
        return 5;
    }
    if (emp2.hire_date.month < 1 || emp2.hire_date.month > 12) {
        cout << "Error: Month must be between 1 and 12." << endl;
        return 6;
    }
    if (emp2.hire_date.year < 0 || emp2.hire_date.year > 9999) {
        cout << "Error: Year must be between 0 and 9999." << endl;
        return 7;
    }



    /*---------------------------------------- Employee 3 ----------------------------------------*/
    cout << "\nEnter data for employee 3:" << endl;

    cout << "Employee number: ";
    if (!(cin >> emp3.number) || emp3.number < 0) {
        cout << "Error: Expected a positive integer for employee number." << endl;
        return 1;
    }

    cout << "Salary: ";
    if (!(cin >> emp3.salary) || emp3.salary < 0) {
        cout << "Error: Expected a positive number for salary." << endl;
        return 2;
    }

    cout << "Enter the first letter of the position" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;

    switch (first_letter) {
        case 'l': emp3.position = laborer; break;
        case 's': emp3.position = secretary; break;
        case 'm': emp3.position = manager; break;
        case 'a': emp3.position = accountant; break;
        case 'e': emp3.position = executive; break;
        case 'r': emp3.position = researcher; break;
        default:{
            cout << "Error: Invalid first letter." << endl;
            return 3;
        }
    }

    cout << "Enter hire date (dd/mm/yyyy): ";
    cin >> emp3.hire_date.day >> slash1 >> emp3.hire_date.month >> slash2 >> emp3.hire_date.year;

    if (slash1 != '/' || slash2 != '/') {
        cout << "Error: Invalid date format. Please use dd/mm/yyyy." << endl;
        return 4;
    }
    if (emp3.hire_date.day < 1 || emp3.hire_date.day > 31) {
        cout << "Error: Day must be between 1 and 31." << endl;
        return 5;
    }
    if (emp3.hire_date.month < 1 || emp3.hire_date.month > 12) {
        cout << "Error: Month must be between 1 and 12." << endl;
        return 6;
    }
    if (emp3.hire_date.year < 0 || emp3.hire_date.year > 9999) {
        cout << "Error: Year must be between 0 and 9999." << endl;
        return 7;
    }



    /*---------------------------------------- Output ----------------------------------------*/
    cout << "\nEmployee information:" << endl;

    cout << "\nEmployee 1:" << endl;
    cout << "Number: " << emp1.number << endl;
    cout << "Salary: $" << emp1.salary << endl;
    cout << "Position: ";
    switch (emp1.position) {
        case laborer: cout << "laborer"; break;
        case secretary: cout << "secretary"; break;
        case manager: cout << "manager"; break;
        case accountant: cout << "accountant"; break;
        case executive: cout << "executive"; break;
        case researcher: cout << "researcher"; break;
    }
    cout << endl;
    cout << "Hire date: "
         << setw(2) << setfill('0') << emp1.hire_date.day << "/"
         << setw(2) << setfill('0') << emp1.hire_date.month << "/"
         << setw(4) << setfill('0') << emp1.hire_date.year << endl;

    cout << "\nEmployee 2:" << endl;
    cout << "Number: " << emp2.number << endl;
    cout << "Salary: $" << emp2.salary << endl;
    cout << "Position: ";
    switch (emp2.position) {
        case laborer: cout << "laborer"; break;
        case secretary: cout << "secretary"; break;
        case manager: cout << "manager"; break;
        case accountant: cout << "accountant"; break;
        case executive: cout << "executive"; break;
        case researcher: cout << "researcher"; break;
    }
    cout << endl;
    cout << "Hire date: "
         << setw(2) << setfill('0') << emp2.hire_date.day << "/"
         << setw(2) << setfill('0') << emp2.hire_date.month << "/"
         << setw(4) << setfill('0') << emp2.hire_date.year << endl;

    cout << "\nEmployee 3:" << endl;
    cout << "Number: " << emp3.number << endl;
    cout << "Salary: $" << emp3.salary << endl;
    cout << "Position: ";
    switch (emp3.position) {
        case laborer: cout << "laborer"; break;
        case secretary: cout << "secretary"; break;
        case manager: cout << "manager"; break;
        case accountant: cout << "accountant"; break;
        case executive: cout << "executive"; break;
        case researcher: cout << "researcher"; break;
    }
    cout << endl;
    cout << "Hire date: "
         << setw(2) << setfill('0') << emp3.hire_date.day << "/"
         << setw(2) << setfill('0') << emp3.hire_date.month << "/"
         << setw(4) << setfill('0') << emp3.hire_date.year << endl;

    return 0;
}

// TODO:
// 1) Use an array of employee structures (employee emp[3]) instead of three separate variables.
// 2) Replace repeated input blocks with a "for" loop (for int i = 0; i < 3; ++i).
// 3) Replace repeated output blocks with a "for" loop.
// 4) Consider using a function to convert etype to string (e.g., positionToString(etype p)).
// 5) Consider using a function to input employee data (e.g., readEmployee(employee &one)).
// 6) Consider using a functions to validate input.
// 7) Use constants for array size (e.g., const int EMPLOYEE_COUNT = 3).
// 8) Use a separate function to display employee information.