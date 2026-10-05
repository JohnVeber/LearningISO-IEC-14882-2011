#include <iostream>
#include <iomanip>
using namespace std;

// Old British currency: 1 pound = 20 shillings, 1 shilling = 12 pence.
const int PENCE_PER_SHILLING = 12;
const int SHILLINGS_PER_POUND = 20;
const char SEPARATOR = '.';    // Separator between pounds, shillings, and pence.

struct sterling {
    int pounds;
    int shillings;
    int pence;
};

sterling get_sterling();
sterling add_sterling(sterling s1, sterling s2);
void show_sterling(const sterling& s);

//--------------------------------------------------------
int main() {
    sterling s1, s2, s3;

    cout << "Enter the first amount of money.";
    s1 = get_sterling();

    cout << "Enter the second amount of money.";
    s2 = get_sterling();

    // Addition.
    s3 = add_sterling(s1, s2);

    // Output the result.
    cout << "\nThe sum of entered values is: "; show_sterling(s3);
    cout << endl;

    return 0;
}

// ---------------------Function №1------------------------
// Gets number of pounds, shillings and pence from user and returns a "sterling" struct with the entered values.
sterling get_sterling() {
    sterling s;

    cout << "\nEnter pounds: ";
    if (!(cin >> s.pounds) || s.pounds < 0) {
        cout << "Error: Pounds must be a non-negative integer." << endl;
        exit(1);
    }

    cout << "Enter shillings (0-" << SHILLINGS_PER_POUND - 1 << "): ";
    if (!(cin >> s.shillings) || s.shillings < 0 || s.shillings >= SHILLINGS_PER_POUND) {
        cout << "Error: Shillings must be between 0 and " << SHILLINGS_PER_POUND - 1 << "." << endl;
        exit(2);
    }

    cout << "Enter pence (0-" << PENCE_PER_SHILLING - 1 << "): ";
    if (!(cin >> s.pence) || s.pence < 0 || s.pence >= PENCE_PER_SHILLING) {
        cout << "Error: Pence must be between 0 and " << PENCE_PER_SHILLING - 1 << "." << endl;
        exit(3);
    }

    return s;
}

// ---------------------Function №2------------------------
// Adds two "sterling" values and returns the result (also "sterling" type).
sterling add_sterling(sterling s1, sterling s2) {
    sterling s3;

    s3.pence = s1.pence + s2.pence;
    s3.shillings = s1.shillings + s2.shillings;
    s3.pounds = s1.pounds + s2.pounds;

    // Transfer pence into shillings (12 pence = 1 shilling).
    if (s3.pence >= PENCE_PER_SHILLING) {
        s3.pence -= PENCE_PER_SHILLING;
        s3.shillings++;
    }

    // Transfer shillings into pounds (20 shillings = 1 pound).
    if (s3.shillings >= SHILLINGS_PER_POUND) {
        s3.shillings -= SHILLINGS_PER_POUND;
        s3.pounds++;
    }

    return s3;
}

// ---------------------Function №3------------------------
// Displays a sterling value in the format "£pounds.shillings.pence".

void show_sterling(const sterling& s) { // A keyword "const" is added as a guarantee that function will not change the variable.
    cout << "\xC2\xA3" // UTF-8 character "£" takes 2 bytes (0xC2 and 0xA3).
    << s.pounds << SEPARATOR
    << setw(2) << setfill('0') << s.shillings << SEPARATOR
    << setw(2) << setfill('0') << s.pence;
}