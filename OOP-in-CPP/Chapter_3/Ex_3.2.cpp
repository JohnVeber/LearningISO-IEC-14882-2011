#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double OFFSET = 32.0;
    const double CELSIUS_TO_FAHRENHEIT = 9.0 / 5.0;
    const double FAHRENHEIT_TO_CELSIUS = 5.0 / 9.0;

    double temperature = 0.0;
    double result = 0.0;

    cout << "Press 1 to convert Celsius to Fahrenheit " << endl;
    cout << "or 2 to convert Fahrenheit to Celsius: ";

    /*................Rationale for using getline() to read user input: .................
        Using getline() reads the entire input line as a string.
        This prevents leftover data (e.g., ".5" from "1.5") from staying in the buffer.
        We then check that the line is exactly one character long,
        which rejects invalid inputs like "1.5", "12", or "abc".
        Only after this validation do we extract the first character.
    .....................................................................................*/
    string input_line;
    getline(cin, input_line);
    if (input_line.length() != 1 || (input_line[0] != '1' && input_line[0] != '2')) {
        cout << "Error: Invalid input. Please enter exactly 1 or 2." << endl;
        cout << "The program will now terminate." << endl;
        return 1;
    }

    /*...............Rationale for using char for the 'option' variable: .................
        If we used int, we would get the ASCII code (e.g., 49 for '1'),
         which would complicate the code and reduce readability.
        Using char allows us to use '1' and '2' directly in the switch cases.
    .....................................................................................*/
    char option = input_line[0];    // Declaring variable directly before its place of usage immediate initialization.
    switch (option) {
        case '1':
            cout << "Enter temperature in Celsius: ";
            if (!(cin >> temperature)) {
                cout << "Error: Invalid input. Please enter a number." << endl;
                cout << "The program will now terminate." << endl;
                return 1;
            }
            result = temperature * CELSIUS_TO_FAHRENHEIT + OFFSET;
            cout << fixed << setprecision(6);   // Set output format
            cout << "Equivalent in Fahrenheit: " << result << endl;
            break;

        case '2':
            cout << "Enter temperature in Fahrenheit: ";
            if (!(cin >> temperature)) {
                cout << "Error: Invalid input. Please enter a number." << endl;
                cout << "The program will now terminate." << endl;
                return 1;
            }
            result = (temperature - OFFSET) * FAHRENHEIT_TO_CELSIUS;
            cout << fixed << setprecision(6);   // Set output format
            cout << "Equivalent in Celsius: " << result << endl;
            break;

        // No default needed: input has already been validated as '1' or '2'.
    }

    return 0;
}