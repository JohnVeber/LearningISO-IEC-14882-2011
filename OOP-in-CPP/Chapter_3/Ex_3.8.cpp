#include <iostream>
using namespace std;

#define POUND_SIGN "\xC2\xA3"

int main() {
    int f1, s1, p1;
    int f2, s2, p2;
    int f, s, p;
    char choice;

    do {
        f = s = p = 0;

        cout << "Enter two amounts in pounds, shillings, and pence (separated by spaces):" << endl;
        cout << "First amount: " << POUND_SIGN;
        cin >> f1 >> s1 >> p1;

        // Normalize first amount (from smallest unit to largest)
        s1 = s1 + p1 / 12;   // Convert pence to shillings
        p1 = p1 % 12;        // Keep remaining pence
        f1 = f1 + s1 / 20;   // Convert shillings to pounds
        s1 = s1 % 20;        // Keep remaining shillings

        cout << "Second amount: " << POUND_SIGN;
        cin >> f2 >> s2 >> p2;

        // Normalize second amount
        s2 = s2 + p2 / 12;
        p2 = p2 % 12;
        f2 = f2 + s2 / 20;
        s2 = s2 % 20;

        // Add pence
        p = p1 + p2;
        while (p >= 12) {
            p -= 12;
            s++;
        }

        // Add shillings
        s = s + s1 + s2;
        while (s >= 20) {
            s -= 20;
            f++;
        }

        // Add pounds
        f = f + f1 + f2;

        cout << "Total: " << POUND_SIGN << f << " " << s << " " << p << endl;

        cout << "Continue (y/n)? ";
        if (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cout << "Invalid input. Program terminated." << endl;
            return 1;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// TODO:
// 1) Refactor input to accept dot-separated format (e.g., £5.10.6) instead of space-separated.
// 2) Use getline() to read the entire line, then parse integers between dots.
// 3) Update prompt messages to reflect the new expected input format.