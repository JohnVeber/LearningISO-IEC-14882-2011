#include <iostream>
using namespace std;

int main() {
    const char POUND_SIGN[] = "\xC2\xA3";
    const char SEPARATOR = '.';
    const int PENCE_PER_POUND = 240;
    const int PENCE_PER_SHILLING = 12;

    int f1, s1, p1;
    int f2, s2, p2;
    char operation;
    int total_pence;
    int result_f, result_s, result_p;
    char choice;
    double multiplier;

    do {
        // Input and validate the operation
        do {
            cout << "Enter operation (+, -, *):" << endl;
            cout << "'+' - add two amounts" << endl;
            cout << "'-' - subtract two amounts" << endl;
            cout << "'*' - multiply an amount by a real number" << endl;
            cout << "Your choice is: ";
            cin >> operation;

            if (operation != '+' && operation != '-' && operation != '*') {
                cout << "Error: Invalid operation. Please enter +, -, or *." << endl;
            }
        } while (operation != '+' && operation != '-' && operation != '*');

        switch (operation) {
            case '+': {
                cout << "Enter first amount (pounds shillings pence): " << POUND_SIGN;
                cin >> f1 >> s1 >> p1;

                cout << "Enter second amount (pounds shillings pence): " << POUND_SIGN;
                cin >> f2 >> s2 >> p2;

                // Convert both amounts to pence and add them
                total_pence = (f1 * PENCE_PER_POUND + s1 * PENCE_PER_SHILLING + p1)
                            + (f2 * PENCE_PER_POUND + s2 * PENCE_PER_SHILLING + p2);

                // Convert the result from pence back to pounds, shillings, and pence
                result_f = total_pence / PENCE_PER_POUND;
                total_pence %= PENCE_PER_POUND;
                result_s = total_pence / PENCE_PER_SHILLING;
                result_p = total_pence % PENCE_PER_SHILLING;

                cout << "Result: " << POUND_SIGN << result_f << SEPARATOR << result_s << SEPARATOR << result_p << endl;
                break;
            }

            case '-': {
                cout << "Enter first amount (pounds shillings pence): " << POUND_SIGN;
                cin >> f1 >> s1 >> p1;

                cout << "Enter second amount (pounds shillings pence) - must be less than the first amount: " << POUND_SIGN;
                cin >> f2 >> s2 >> p2;

                // Convert both amounts to pence and subtract them
                total_pence = (f1 * PENCE_PER_POUND + s1 * PENCE_PER_SHILLING + p1)
                            - (f2 * PENCE_PER_POUND + s2 * PENCE_PER_SHILLING + p2);

                // Check for negative result
                if (total_pence < 0) {
                    cout << "Error: The first amount must be greater than the second one for subtraction." << endl;
                } else {
                    // Convert the result from pence back to pounds, shillings, and pence
                    result_f = total_pence / PENCE_PER_POUND;
                    total_pence %= PENCE_PER_POUND;
                    result_s = total_pence / PENCE_PER_SHILLING;
                    result_p = total_pence % PENCE_PER_SHILLING;

                    cout << "Result: " << POUND_SIGN << result_f << SEPARATOR << result_s << SEPARATOR << result_p << endl;
                }
                break;
            }

            case '*': {
                cout << "Enter amount (pounds shillings pence): " << POUND_SIGN;
                cin >> f1 >> s1 >> p1;

                cout << "Enter multiplier (as a decimal number): ";
                cin >> multiplier;

                // Convert the amount to pence and multiply by the multiplier
                total_pence = static_cast<int>((f1 * PENCE_PER_POUND + s1 * PENCE_PER_SHILLING + p1) * multiplier); // Using explicit cast

                // Convert the result from pence back to pounds, shillings, and pence
                result_f = total_pence / PENCE_PER_POUND;
                total_pence %= PENCE_PER_POUND;
                result_s = total_pence / PENCE_PER_SHILLING;
                result_p = total_pence % PENCE_PER_SHILLING;

                cout << "Result: " << POUND_SIGN << result_f << SEPARATOR << result_s << SEPARATOR << result_p << endl;
                break;
            }
        }

        cout << "One more operation (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}