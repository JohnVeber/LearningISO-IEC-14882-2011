#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date() : month(0), day(0), year(0) { } // Default constructor: initializes all fields to zero.

    // Method for reading a date from the user in MM/DD/YY format.
    // Repeats the request until valid input is entered.
    void getdate() {
        char slash; // For the '/' separator.

        while (true) {
            cout << "Enter date (MM/DD/YY): ";

            // Read month and the first separator.
            cin >> month >> slash;
            if (!cin || slash != '/') {
                cin.clear();             // Reset the error flag on cin.
                cin.ignore(10000, '\n'); // Discard the invalid input.
                cout << "Error: use MM/DD/YY format (e.g., 12/31/02). Try again." << endl;
                continue;
            }

            // Read day and the second separator.
            cin >> day >> slash;
            if (!cin || slash != '/') {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: use MM/DD/YY format (e.g., 12/31/02). Try again." << endl;
                continue;
            }

            // Read year.
            cin >> year;
            if (!cin) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: invalid year. Try again." << endl;
                continue;
            }

            // Check the ranges.
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

            break; // All checks passed.
        }
    }

    void showdate() const { // Constant method: prints the date in MM/DD/YY format with leading zeros.
        cout << setfill('0') // Set the character used for padding to '0'.
             << setw(2) << month << "/"
             << setw(2) << day << "/"
             << setw(2) << year
             << setfill(' ') << endl; // Restore fill character to space.
    }
};

int main() {
    Date d;

    d.getdate();
    cout << "You entered: ";
    d.showdate();

    return 0;
}