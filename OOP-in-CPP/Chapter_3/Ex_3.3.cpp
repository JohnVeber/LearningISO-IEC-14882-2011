#include <iostream>
#include <cstdio>   // For getchar() usage (as cross-platform analog of getche() .)
using namespace std;

int main() {
    const string PROMPT = "Enter six digits: ";
    const string ERROR_LENGTH = "\nError: You must enter exactly 6 digits.";
    const string ERROR_CHAR = "\nError: Invalid character '";
    const string ERROR_CHAR_SUFFIX = "' entered. Only digits are allowed.";
    const string RESULT = "\nYou entered the number: ";

    long number = 0;
    char digit;
    int count = 0;

    cout << PROMPT;

    while (count < 6) {
        digit = getchar();

        // Input validation
        if (digit >= '0' && digit <= '9') {
            number = number * 10 + (digit - '0');
            ++count;
        }
        else if (digit == '\n' || digit == EOF) {
            if (count < 6) {
                cout << ERROR_LENGTH << endl;
                return 1;
            }
        }
        else {
            cout << ERROR_CHAR << digit << ERROR_CHAR_SUFFIX << endl;
            return 1;
        }
    }

    cout << RESULT << number << endl;

    return 0;
}
/*.............................NOTE...........................................
 This program reads exactly 6 digits from the input buffer.
If user enters more than 6 characters, the extra characters remain
 in the input buffer until the program terminates.
Since the program ends immediately after reading the 6 digits,
 this does not affect the program's output or behavior.
This is acceptable as the task does not require handling additional input.
 ............................................................................*/