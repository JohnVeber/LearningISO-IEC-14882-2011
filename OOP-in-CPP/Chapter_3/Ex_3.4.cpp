#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double operand_1 = 0.0;
    double operand_2 = 0.0;
    double result = 0.0;
    char operation = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter the first operand, operation, and the second operand: ";
        // Close the program in case of incorrect input
        if (!(cin >> operand_1 >> operation >> operand_2)) {
            cout << "Error: Invalid input. Please follow the format: 'number' 'operator' 'number'" << endl;
            return 1;   // Exit with error code 1.
        }

        bool valid = true; // Initializing the result correctness flag

        switch (operation) {
            case '+':
                result = operand_1 + operand_2;
                break;
            case '-':
                result = operand_1 - operand_2;
                break;
            case '*':
                result = operand_1 * operand_2;
                break;
            case '/':
                if (operand_2 != 0.0) {
                    result = operand_1 / operand_2;
                } else {
                    cout << "Error: Division by zero." << endl;
                    valid = false;
                }
                break;
            default:
                cout << "Error: Invalid operation. Only +, -, * or / operations are allowed." << endl;
                valid = false;
                break;
        }

        if (valid) {
            long long integer_part = static_cast<long long>(result); // Cast the result to long long type to discard its fractional part.
            double fractional_part = result - integer_part; // Calculate the fractional part

            // If the fractional part is zero, the value is whole, so we use integer output format to avoid unnecessary decimal places.
            if (fractional_part == 0.0) {
                cout << "Result equals " << integer_part << endl;
            } else {
                // Otherwise, we use fixed-point format with 6 decimal places for better precision.
                cout << fixed << setprecision(6) << "Result equals " << result << endl;
            }
        }

        cout << "Do another operation (y/n)? ";
        cin >> choice;
    }
    return 0;
}


// TODO:
// 1) Handling of choice's input.
// 2) Check if the fractional part is in a very small range (epsilon).