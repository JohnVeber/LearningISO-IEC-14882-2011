#include <iostream>
using namespace std;

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    fraction f1, f2, result;
    char slash;

    cout << "Enter the first fraction in a/b format: ";
    cin >> f1.numerator >> slash >> f1.denominator;
    if (slash != '/') {
        cout << "Error: Expected '/' separator in the first fraction." << endl;
        return 1;   // Error code for invalid separator
    }
    if (f1.denominator == 0) {
        cout << "Error: Denominator of the first fraction cannot be zero." << endl;
        return 2;   // Error code for zero denominator
    }

    cout << "Enter the second fraction in the same format: ";
    cin >> f2.numerator >> slash >> f2.denominator;
    if (slash != '/') {
        cout << "Error: Expected '/' separator in the second fraction." << endl;
        return 1;
    }
    if (f2.denominator == 0) {
        cout << "Error: Denominator of the second fraction cannot be zero." << endl;
        return 2;
    }

    // Addition: a/b + c/d = (a*d + b*c) / (b*d)
    result.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;

    cout << "The sum of fractions is: " << result.numerator << "/" << result.denominator << endl;

    return 0;
}

// TODO:
// 1) Implement fraction reduction (simplification) using the greatest common divisor.