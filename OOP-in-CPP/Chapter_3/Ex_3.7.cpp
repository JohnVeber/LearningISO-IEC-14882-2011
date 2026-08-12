#include <iostream>
using namespace std;

int main() {
    double deposit = 0.0;
    int years = 0;
    double rate = 0.0;
    double total = 0.0;

    cout << "Enter initial deposit: ";
    cin >> deposit;
    cout << "Enter number of years: ";
    cin >> years;
    cout << "Enter interest rate: ";
    cin >> rate;

    for (int i = 0; i < years; ++i) {
        deposit = deposit * (1 + rate / 100.0);
        total = deposit;
    }

    cout << "After " << years << " years you will receive " << total << " dollars." << endl;

    return 0;
}

// TODO:
// 1) Handling of input data.