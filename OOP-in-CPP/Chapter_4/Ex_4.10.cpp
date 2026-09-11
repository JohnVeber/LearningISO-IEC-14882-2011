#include <iostream>
using namespace std;

struct sterling {
    int pounds;
    int shillings;
    int pence;
};

int main() {
    double decimal_pounds;
    sterling old_money;

    cout << "Enter amount in decimal pounds: ";
    if (!(cin >> decimal_pounds) || decimal_pounds < 0) {
        cout << "Error: Expected a non-negative number." << endl;
        return 1;
    }

    // Extract pounds (integer part)
    old_money.pounds = static_cast<int>(decimal_pounds);

    // Extract fractional part
    double fractional = decimal_pounds - old_money.pounds;

    // Convert fractional part to shillings (1 pound = 20 shillings)
    old_money.shillings = static_cast<int>(fractional * 20);

    // Convert remaining fraction to pence (1 shilling = 12 pence)
    double fractional_shillings = fractional * 20 - old_money.shillings;
    old_money.pence = static_cast<int>(fractional_shillings * 12 + 0.5); // +0.5 for rounding

    cout << "Equivalent in old system: £"
         << old_money.pounds << "."
         << old_money.shillings << "."
         << old_money.pence << endl;

    return 0;
}