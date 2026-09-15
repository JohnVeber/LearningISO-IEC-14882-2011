#include <iostream>
#include <iomanip>  // for setprecision
using namespace std;

// Function to calculate the area of a circle
float circarea(float radius) {
    const float PI = 3.14159F;
    return PI * radius * radius;
}

int main() {
    float rad;

    cout << "Enter the radius of the circle: ";
    if (!(cin >> rad) || rad < 0) {
        cout << "Error: Expected a non-negative number for the radius." << endl;
        return 1;
    }

    float area = circarea(rad);

    cout << fixed << setprecision(6);  // Set output format to 6 decimal places
    cout << "The area of the circle is " << area << endl;

    return 0;
}