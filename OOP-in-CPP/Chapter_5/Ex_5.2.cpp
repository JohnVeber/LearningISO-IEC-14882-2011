#include <iostream>
using namespace std;

// Function to raise n to the power p
// Default value for p is 2 (squaring)
double power(double n, int p = 2) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) {
        result *= n;
    }
    return result;
}

int main() {
    double n;
    int p;

    cout << "Enter the base number (n): ";
    if (!(cin >> n)) {
        cout << "Error: Expected a number for the base." << endl;
        return 1;
    }

    cout << "Enter the exponent (p) or press Enter to square: ";
    // Try to read p; if it fails (e.g., user pressed Enter), use default
    if (!(cin >> p)) {
        cin.clear();           // Clear the error state
        cin.ignore(1000, '\n'); // Discard invalid input
        p = 2;                 // Use default exponent
    }

    double result = power(n, p);

    cout << n << " raised to the power " << p << " is " << result << endl;

    return 0;
}