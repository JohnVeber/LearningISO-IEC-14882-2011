#include <iostream>
using namespace std;

//--------------------------------------------------------
// Prototypes: five overloads of power() with the same name.
// Order: double (base from ex.2), then char, int, long, float.
double power(double n, int p = 2);
double power(char   n, int p = 2);
double power(int    n, int p = 2);
double power(long   n, int p = 2);
double power(float  n, int p = 2);

//--------------------------------------------------------
int main() {
    // Ask once whether to enter an exponent (same logic as in ex.2)
    cout << "Do you want to enter an exponent? (y/n): ";
    char yesNo;
    if (!(cin >> yesNo)) {
        cout << "Error: could not read a character. Aborting." << endl;
        return 1;
    }

    int exponent = 2; // default

    if (yesNo == 'y' || yesNo == 'Y') {
        cout << "Enter the exponent (p): ";
        if (!(cin >> exponent) || exponent < 0) {
            cout << "Warning: exponent not recognized. Using default value 2." << endl;
            cin.clear();                 // reset fail state
            cin.ignore(1000, '\n');      // discard the rest of the line
            exponent = 2; // C++11+ (and newer): failed extraction sets exponent to 0; restore the default to avoid it.
        }
    }

    cout << endl;

    // --- double ---
    double d;
    cout << "Enter a double value: ";
    if (!(cin >> d)) {
        cout << "Error: bad double input. Aborting." << endl;
        return 2;
    }
    cout << "power(double " << d << ", " << exponent << ") = " << power(d, exponent) << endl;

    // --- char ---
    char c;
    cout << "Enter a char value: ";
    if (!(cin >> c)) {
        cout << "Error: bad char input. Aborting." << endl;
        return 3;
    }
    cout << "power(char '" << c << "' [" << static_cast<int>(c) << "], " << exponent << ") = " << power(c, exponent) << endl;

    // --- int ---
    int i;
    cout << "Enter an int value: ";
    if (!(cin >> i)) {
        cout << "Error: bad int input. Aborting." << endl;
        return 4;
    }
    cout << "power(int " << i << ", " << exponent << ") = " << power(i, exponent) << endl;

    // --- long ---
    long l;
    cout << "Enter a long value: ";
    if (!(cin >> l)) {
        cout << "Error: bad long input. Aborting." << endl;
        return 5;
    }
    cout << "power(long " << l << ", " << exponent << ") = " << power(l, exponent) << endl;

    // --- float ---
    float f;
    cout << "Enter a float value: ";
    if (!(cin >> f)) {
        cout << "Error: bad float input. Aborting." << endl;
        return 6;
    }
    cout << "power(float " << f << ", " << exponent << ") = " << power(f, exponent) << endl;

    return 0;
}

//--------------------------------------------------------

double power(double n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) result *= n;
    return result;
}

double power(char n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) result *= n;
    return result;
}

double power(int n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) result *= n;
    return result;
}

double power(long n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) result *= n;
    return result;
}

double power(float n, int p) {
    double result = 1.0;
    for (int i = 0; i < p; ++i) result *= n;
    return result;
}

// TODO:
// 1) Add input validation.