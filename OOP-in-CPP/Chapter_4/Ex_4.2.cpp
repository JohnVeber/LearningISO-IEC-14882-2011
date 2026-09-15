#include <iostream>
using namespace std;

struct point {
    int x;
    int y;
};

int main() {
    cout << "Enter coordinates of the point p1: ";
    point p1 = {0, 0};
    // Input check
    if (!(cin >> p1.x) || !(cin >> p1.y)) {
        cout << "Error: Integers are expected for the coordinates." << endl;
        return 1;
    }

    cout << "Enter coordinates of the point p2: ";
    point p2 = {0, 0};
    // Input check
    if (!(cin >> p2.x) || !(cin >> p2.y)) {
        cout << "Error: Integers are expected for the coordinates." << endl;
        return 2;
    }

    point result = {0, 0};
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;

    cout << "Coordinates of point p1+p2 are equal: " << result.x << ", " << result.y << endl;

    return 0;
}

// TODO:
// 1) Retry request in case of input errors.