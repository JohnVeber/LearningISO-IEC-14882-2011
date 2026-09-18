#include <iostream>
using namespace std;

double raiseToPower(double, int = 2); // Prototype with default argument

int main() {
    double number;
    int power;

    cout << "Enter the base number (n): ";
    if (!(cin >> number)) {
        cout << "Error: Expected a number for the base." << endl;
        return 1;
    }

    cout << "Enter the exponent (p) or press Enter to square: ";
    if (!(cin >> power)) {
        cin.clear();              // Clear error state
        cin.ignore(1000, '\n');   // Discard invalid input
        power = 2;                // Use default exponent
        cout << "Warning: Could not read exponent. Using default value 2." << endl;
    }

    // Check that exponent is non-negative
    if (power < 0) {
        cout << "Error: Exponent must be a non-negative integer." << endl;
        return 2;
    }

    double result = raiseToPower(number, power);

    cout << number << " raised to the power " << power << " is " << result << endl;

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
// 1) Handle Enter key press for the exponent input using cin.peek() or getline().
// 2) Add overflow protection for large exponents (e.g., check if result exceeds double limits).