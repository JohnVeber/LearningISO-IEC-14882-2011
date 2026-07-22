#include <iostream>
using namespace std;
int main() {
    int number;
    int multiplier = 1;

    cout << "Enter an integer number: ";

    // Input check
    if (!(cin >> number)) {
        cout << "Error: Invalid input. Please enter an integer number." << endl;
        cout << "The program will now terminate." << endl;
        return 1;
    }

    // Generating a multiplication table of 20 rows and 10 columns
    for (int row = 0; row < 20; ++row) {
        for (int col = 0; col < 10; ++col) {
            cout << number * multiplier;
            ++multiplier;
        }
        cout << endl;
    }

    return 0;
}