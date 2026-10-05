#include <iostream>
#include <cstdlib> // For exit() function; see IWYU principle.
using namespace std;

struct fraction {
    int numerator;
    int denominator;
};

fraction fadd(fraction firstFraction, fraction secondFraction);
fraction fsub(fraction firstFraction, fraction secondFraction);
fraction fmul(fraction firstFraction, fraction secondFraction);
fraction fdiv(fraction firstFraction, fraction secondFraction);

int main() {
    fraction f1, f2, result;
    char slash;             // For the '/' separator.
    char operation;         // Operation (+, -, *, /).
    char choice;            // Continue or not.

    do {
        // Input first fraction.
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

        // Input operation.
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Error: Invalid operation. Please use +, -, *, or /." << endl;
            return 5;
        }

        // Input second fraction.
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

        // 1st division by zero check (in the calling program).
        if (operation == '/' && f2.numerator == 0) {
            cout << "Error: Division by zero." << endl;
            return 10;
        }

        // Perform calculation based on the operation.
        switch (operation) {
            case '+':
                result = fadd(f1, f2);
                break;
            case '-':
                result = fsub(f1, f2);
                break;
            case '*':
                result = fmul(f1, f2);
                break;
            case '/':
                result = fdiv(f1, f2);
                break;
        }

        // Output result.
        cout << "Result: " << result.numerator << "/" << result.denominator << endl;

        // Ask for continuation.
        cout << "One more operation (y/n)? ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Error: Invalid input. Please enter 'y' or 'n'." << endl;
            return 11;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// ---------------------Function №1------------------------
// fadd() - addition of two variables with "fraction" type.
fraction fadd(fraction firstFraction, fraction secondFraction) {
    fraction resultFraction;

    resultFraction.numerator = firstFraction.numerator * secondFraction.denominator + firstFraction.denominator * secondFraction.numerator;
    resultFraction.denominator = firstFraction.denominator * secondFraction.denominator;

    return resultFraction;
}

// ---------------------Function №2------------------------
// fsub() - subtraction of two variables with "fraction" type.
fraction fsub(fraction firstFraction, fraction secondFraction) {
    fraction resultFraction;

    resultFraction.numerator = firstFraction.numerator * secondFraction.denominator - firstFraction.denominator * secondFraction.numerator;
    resultFraction.denominator = firstFraction.denominator * secondFraction.denominator;

    return resultFraction;
}

// ---------------------Function №3------------------------
// fmul() - multiplication of two variables with "fraction" type.
fraction fmul(fraction firstFraction, fraction secondFraction) {
    fraction resultFraction;

    resultFraction.numerator = firstFraction.numerator * secondFraction.numerator;
    resultFraction.denominator = firstFraction.denominator * secondFraction.denominator;

    return resultFraction;
}

// ---------------------Function №4------------------------
// fdiv() - division of the first fraction by the second one.

fraction fdiv(fraction firstFraction, fraction secondFraction) {
    fraction resultFraction;
    if (secondFraction.numerator == 0) { // 2nd division by zero check (inside the function).
        cout << "Error: You are trying to divide by zero!" << endl;
        exit(12);
    }
    resultFraction.numerator = firstFraction.numerator * secondFraction.denominator;
    resultFraction.denominator = firstFraction.denominator * secondFraction.numerator;

    return resultFraction;
}

// TODO:
// 1) Implement fraction reduction (simplification) using the greatest common divisor.
// 2) Avoid exit() inside fdiv(); let the caller handle the error.