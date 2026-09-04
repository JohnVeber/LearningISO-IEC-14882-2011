#include <iostream>
using namespace std;

int main() {
    int seats, guests;
    do {

    seats = 0;
    cout << "Enter the number of seats at the table: ";
        if (!(cin >> seats) || (seats <= 0)) {
            cout << "Error: Invalid input. Expected a positive integer." << endl;
            cout << "The program will now terminate." << endl;
            return 1;
        }

    guests = 0;
    cout << "Enter the number of guests (must be greater than the number of seats): ";
        if (!(cin >> guests) || (guests <= 0)) {
            cout << "Error: Invalid input. Expected a positive integer." << endl;
            cout << "The program will now terminate." << endl;
            return 2;
        }

        if (seats >= guests){
            cout << "Error: Number of guests must be greater than number of seats, please try again." << endl;
        }
    }
    while (seats >= guests);

    long long positions = 1;
        for (int i = seats; i > 0; --i){
            positions = positions * guests;
            --guests;
        }
    cout << "The number of possible seating arrangements is " << positions << endl;
    return 0;
}

// TODO:
// 1) Add overflow protection for long long when computing arrangements.