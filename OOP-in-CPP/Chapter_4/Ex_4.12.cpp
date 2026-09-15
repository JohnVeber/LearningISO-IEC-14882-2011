#include <iostream>
using namespace std;

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    fraction f1, f2, result;
    char slash;             // For the '/' separator
    char operation;         // Operation (+, -, *, /)
    char choice;            // Continue or not

    do {
        // Input first fraction
        cout << "Enter the first fraction (a/b): ";
        if (!(cin >> f1.numerator)) {
            cout << "Error: Expected an integer for the numerator of the first fraction." << endl;
            return 1;
        }
        if (!(cin >> slash) || slash != '/') {
            cout << "Error: Expected '/' separator in the first fraction." << endl;
            return 2;
        }
        if (!(cin >> f1.denominator)) {
            cout << "Error: Expected an integer for the denominator of the first fraction." << endl;
            return 3;
        }
        if (f1.denominator == 0) {
            cout << "Error: Denominator of the first fraction cannot be zero." << endl;
            return 4;
        }

        // Input operation
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Error: Invalid operation. Please use +, -, *, or /." << endl;
            return 5;
        }

        // Input second fraction
        cout << "Enter the second fraction (c/d): ";
        if (!(cin >> f2.numerator)) {
            cout << "Error: Expected an integer for the numerator of the second fraction." << endl;
            return 6;
        }
        if (!(cin >> slash) || slash != '/') {
            cout << "Error: Expected '/' separator in the second fraction." << endl;
            return 7;
        }
        if (!(cin >> f2.denominator)) {
            cout << "Error: Expected an integer for the denominator of the second fraction." << endl;
            return 8;
        }
        if (f2.denominator == 0) {
            cout << "Error: Denominator of the second fraction cannot be zero." << endl;
            return 9;
        }

        // Division by zero check
        if (operation == '/' && f2.numerator == 0) {
            cout << "Error: Division by zero." << endl;
            return 10;
        }

        // Perform calculation based on the operation
        switch (operation) {
            case '+':
                result.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
                result.denominator = f1.denominator * f2.denominator;
                break;
            case '-':
                result.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
                result.denominator = f1.denominator * f2.denominator;
                break;
            case '*':
                result.numerator = f1.numerator * f2.numerator;
                result.denominator = f1.denominator * f2.denominator;
                break;
            case '/':
                result.numerator = f1.numerator * f2.denominator;
                result.denominator = f1.denominator * f2.numerator;
                break;
        }

        // Output result
        cout << "Result: " << result.numerator << "/" << result.denominator << endl;

        // Ask for continuation
        cout << "One more operation (y/n)? ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Error: Invalid input. Please enter 'y' or 'n'." << endl;
            return 11;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// TODO:
// 1) Implement fraction reduction (simplification) using the greatest common divisor.