#include <iostream>
using namespace std;

void swap(int& a, int& b);

//--------------------------------------------------------
int main() {
    int x, y;

    cout << "Enter the first value (x): ";
    if (!(cin >> x)) {
        cout << "Error: bad input for x. Aborting." << endl;
        return 1;
    }

    cout << "Enter the second value (y): ";
    if (!(cin >> y)) {
        cout << "Error: bad input for y. Aborting." << endl;
        return 2;
    }

    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "After  swap: x = " << x << ", y = " << y << endl;

    return 0;
}

//--------------------------------------------------------
// Function to swap two int values (passed by reference)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}