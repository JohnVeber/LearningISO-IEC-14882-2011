#include <iostream>
using namespace std;

int main() {
    double deposit = 0.0;
    double rate = 0.0;
    double target = 0.0;
    int years = 0; // Need to be calculated

    cout << "Enter initial deposit: ";
    if (!(cin >> deposit) || deposit <= 0) {
        cout << "Error: Invalid deposit amount. The program will now terminate." << endl;
        return 1;
    }

    cout << "Enter interest rate (%): ";
    if (!(cin >> rate) || rate <= 0) {
        cout << "Error: Interest rate must be positive. The program will now terminate." << endl;
        return 1;
    }

    cout << "Enter target amount: ";
    if (!(cin >> target) || target <= deposit) {
        cout << "Error: Target must be greater than the initial deposit. The program will now terminate." << endl;
        return 1;
    }

    while (deposit < target) {
        deposit = deposit * (1 + rate / 100.0);
        ++years;
    }

    cout << "To accumulate " << target << " dollars at " << rate << "% interest, " << "you will need " << years << " years." << endl;
    return 0;
}

// TODO:
// 1) Handling this value: rate == 0
// 2) Different return codes for each case
// 3) Retry request on error (not finish).