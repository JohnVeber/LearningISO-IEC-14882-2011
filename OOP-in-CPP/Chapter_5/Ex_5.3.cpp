#include <iostream>
using namespace std;

void zeroSmaller(int&, int&);

int main() {
    int x, y;

    cout << "Enter the first number: ";
    if (!(cin >> x)) {
        cout << "Error: Expected an integer." << endl;
        return 1;
    }

    cout << "Enter the second number: ";
    if (!(cin >> y)) {
        cout << "Error: Expected an integer." << endl;
        return 2;
    }

    cout << "Before comparison: x = " << x << ", y = " << y << endl;

    zeroSmaller(x, y);

    cout << "After comparison:  x = " << x << ", y = " << y << endl;

    return 0;
}

// Function to set the smaller argument to zero (passed by reference)
void zeroSmaller(int& a, int& b) {
    if (a < b) {
        a = 0;
    } else if (b < a) {
        b = 0;
    } else {
        cout << "The arguments are equal. No changes made." << endl;
    }
}

// TODO:
// 1) Consider using templates to make zeroSmaller work with any comparable type (int, double, etc.).
// 2) Add a return value (e.g., bool) to indicate whether a change was made.
// 3) Consider passing arguments by pointer instead of reference for C-style compatibility.
