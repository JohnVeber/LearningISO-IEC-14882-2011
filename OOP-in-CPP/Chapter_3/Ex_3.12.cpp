#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d;   // Numerators and denominators of fractions
    char slash;             // For the '/' separator
    char operation;         // Operation (+, -, *, /)
    char choice;            // Continue or not
    long long num, den;     // Numerator and denominator of the result

    do {
        cout << "Enter the first fraction (a/b): ";
        cin >> a >> slash >> b;
        if (slash != '/' || b == 0) {
            cout << "Error: Invalid fraction. Please use the format a/b and ensure denominator is not zero." << endl;
            return 1;
        }

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Error: Invalid operation. Please use +, -, *, or /." << endl;
            return 1;
        }

        cout << "Enter the second fraction (c/d): ";
        cin >> c >> slash >> d;
        if (slash != '/' || d == 0) {
            cout << "Error: Invalid fraction. Please use the format c/d and ensure denominator is not zero." << endl;
            return 1;
        }

        // Division by zero check
        if (operation == '/' && c == 0) {
            cout << "Error: Division by zero." << endl;
            return 1;
        }

        switch (operation) {
            case '+':
                num = a * d + b * c;
                den = b * d;
                break;
            case '-':
                num = a * d - b * c;
                den = b * d;
                break;
            case '*':
                num = a * c;
                den = b * d;
                break;
            case '/':
                num = a * d;
                den = b * c;
                break;
        }

        cout << "Result: " << num << "/" << den << endl;

        cout << "One more operation (y/n)? ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Error: Invalid input. Please enter 'y' or 'n'." << endl;
            return 1;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// TODO:
// 1) Implement automatic reduction of the resulting fraction.