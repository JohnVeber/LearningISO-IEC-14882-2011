#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    long pounds, shillings, pence;
    cout << "Enter pounds: ";
    cin >> pounds;
    cout << "Enter shillings: ";
    cin >> shillings;
    cout << "Enter pence: ";
    cin >> pence;

    // Just convert the entered values to pounds
    double decimal_pounds = pounds + shillings / 20.0 + pence / 240.0;

    // UTF-8 character "£" takes 2 bytes (0xC2 and 0xA3)
    // Make sure your terminal uses UTF-8 encoding; otherwise, this character may not render properly.
    cout << "Decimal pounds: \xC2\xA3"
    << fixed << setprecision(2) << decimal_pounds << endl;
    return 0;
}

/*--------------------------------------------NOTE----------------------------------------------------
The pound sign '£' has Unicode unique codepoint U+00A3 (hex: 0xA3, binary: 10100011).
UTF-8 encodes this character in 2 bytes according to the pattern:
    1st byte: 110xxxxx  (the xxxxx represent the top 5 bits of the codepoint)
    2nd byte: 10xxxxxx  (the xxxxxx represent the bottom 6 bits of the codepoint)
For 0xA3 = 10100011:
    1st byte: 110 + 10100 = 11000010 = 0xC2
    2nd byte: 10 + 100011 = 10100011 = 0xA3
So the UTF-8 representation is: 0xC2 0xA3
-----------------------------------------------------------------------------------------------------*/