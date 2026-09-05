#include <iostream>
#include <locale>
using namespace std;
int main() {
    const int SHILLINGS_PER_POUND = 20;
    const int PENCE_PER_SHILLING = 12;
    const char SEPARATOR = '.';    // Separator between pounds, shillings, and pence

    float decimal_pounds;
    float fractional_pounds;    // Fractional part of pounds
    float fractional_shillings;    // Remainder after extracting shillings
    cout << "Enter decimal pounds: ";
    cin >> decimal_pounds;

    int pounds = static_cast<int>(decimal_pounds);
    fractional_pounds = decimal_pounds - pounds;

    // Convert fractional pounds to shillings (1 pound = 20 shillings)
    int shillings = static_cast<int>(fractional_pounds * SHILLINGS_PER_POUND);
    fractional_shillings = (fractional_pounds * SHILLINGS_PER_POUND) - shillings;

    // Convert remaining fractional shillings to pence (1 shilling = 12 pence)
    int pence = static_cast<int>(fractional_shillings * PENCE_PER_SHILLING);
    // The fractional part of a penny is discarded because old pence
    // were indivisible units (no fractional pence existed).

    // UTF-8 character "£" takes 2 bytes (0xC2 and 0xA3)
    cout << "Equivalent in old notation: \xC2\xA3"
    << pounds << SEPARATOR << shillings << SEPARATOR << pence << endl;

    return 0;
}