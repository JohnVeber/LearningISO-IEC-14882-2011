#include <iostream>
using namespace std;

struct phone {
    int area_code;    // City code (3 digits)
    int exchange;     // Telephone exchange number (3 digits)
    int number;       // Subscriber number (4 digits)
};

int main() {
    phone my_number = {212, 767, 8900}; // Structure initialization for "My Number"
    phone your_number; // Structure declaration for "Your Number"

    cout << "Enter area code, exchange, and number: ";

    // Input check of the first field
    if (!(cin >> your_number.area_code)) {
        cout << "Error: 3 digits expected in this field." << endl;
        return 1;
    }
    if (your_number.area_code < 100 || your_number.area_code > 999) {
        cout << "Error: Area code must be exactly 3 digits." << endl;
        return 1;
    }

    // Input check of the second field
    if (!(cin >> your_number.exchange)) {
        cout << "Error: 3 digits expected in this field." << endl;
        return 2;
    }
    if (your_number.exchange < 100 || your_number.exchange > 999) {
        cout << "Error: Exchange must be exactly 3 digits." << endl;
        return 2;
    }

    // Input check of the third field
    if (!(cin >> your_number.number)) {
        cout << "Error: 4 digits expected in this field." << endl;
        return 3;
    }
    if (your_number.number < 1000 || your_number.number > 9999) {
        cout << "Error: Number must be exactly 4 digits." << endl;
        return 3;
    }

    cout << "My number is: (" << my_number.area_code << ") " << my_number.exchange << "-" << my_number.number << endl;
    cout << "Your number is: (" << your_number.area_code << ") " << your_number.exchange << "-" << your_number.number << endl;

    return 0;
}

// TODO:
// 1) Retry request in case of input errors.