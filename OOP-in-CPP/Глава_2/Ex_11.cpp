#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Set left alignment flag for all subsequent output
    cout << setiosflags(ios::left);

    // Headers
    cout << setw(14) << "Lastname"
         << setw(12) << "Firstname"
         << setw(16) << "Address"
         << setw(18) << "City" << endl;

    // Separator line with hyphens
    // Set fill character to '-' and width equal to each column
    cout << setfill('-')
         << setw(14) << ""
         << setw(12) << ""
         << setw(16) << ""
         << setw(18) << "" << endl;

    // Reset fill character back to space
    cout << setfill(' ');

    // Data rows
    cout << setw(14) << "Petrov"
         << setw(12) << "Vasiliy"
         << setw(16) << "Klenovaya 16"
         << setw(18) << "Saint Petersburg" << endl;

    cout << setw(14) << "Ivanov"
         << setw(12) << "Sergey"
         << setw(16) << "Osinovaya 3"
         << setw(18) << "Nakhodka" << endl;

    cout << setw(14) << "Sidorov"
         << setw(12) << "Ivan"
         << setw(16) << "Berezovaya 21"
         << setw(18) << "Kaliningrad" << endl;

    return 0;
}