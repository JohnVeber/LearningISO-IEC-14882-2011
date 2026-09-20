#include <iostream>
using namespace std;

double raiseToPower(double, int = 2); // Prototype with default argument

int main() {
    double number;
    int power;
    char yesNo;

    cout << "Enter the base number (n): ";
    if (!(cin >> number)) {
        cout << "Error: Expected a number for the base." << endl;
        return 1;
    }

    cout << "Do you want to enter an exponent? (y/n): ";
    cin >> yesNo;

    double result;
    if (yesNo == 'y' || yesNo == 'Y') {
        cout << "Enter the exponent (p): ";
        if (!(cin >> power)) {
            cout << "Error: Expected an integer for the exponent." << endl;
            return 2;
        }
        if (power < 0) {
            cout << "Error: Exponent must be non-negative." << endl;
            return 3;
        }
        result = raiseToPower(number, power); // Two arguments - use the explicitly entered degree
        cout << number << " raised to the power " << power << " is " << result << endl;
    }
    else {
        result = raiseToPower(number); // One argument - use default.
        cout << number << " squared is " << result << endl;
    }

    return 0;
}

double raiseToPower(double n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) {
        result *= n;
    }
    return result;
}

// TODO:
// 1) Add overflow protection for large exponents (e.g., check if result exceeds double limits).