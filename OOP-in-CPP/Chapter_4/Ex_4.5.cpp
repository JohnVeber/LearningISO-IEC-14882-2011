#include <iostream>
#include <iomanip>  // for setw() and setfill()
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

int main() {
    date today;
    char slash1, slash2;

    cout << "Enter date (dd/mm/yyyy): ";
    cin >> today.day >> slash1 >> today.month >> slash2 >> today.year;

    // Check separators
    if (slash1 != '/' || slash2 != '/') {
        cout << "Error: Invalid format. Please use dd/mm/yyyy." << endl;
        return 1;
    }

    // Check day range
    if (today.day < 1 || today.day > 31) {
        cout << "Error: Day must be between 1 and 31." << endl;
        return 2;
    }

    // Check month range
    if (today.month < 1 || today.month > 12) {
        cout << "Error: Month must be between 1 and 12." << endl;
        return 3;
    }

    // Check year range
    if (today.year < 0 || today.year > 9999) { // Year range 0-9999 is chosen to match the 4-digit year format (YYYY).
        cout << "Error: Year must be between 0 and 9999." << endl;
        return 4;
    }

    // Output with leading zeros if needed
    cout << "You entered: "
         << setw(2) << setfill('0') << today.day << "/"
         << setw(2) << setfill('0') << today.month << "/"
         << setw(4) << setfill('0') << today.year << endl;

    return 0;
}

// TODO:
// 1) Validate input using string parsing (e.g., read as string, split by '/', and check length of each part).