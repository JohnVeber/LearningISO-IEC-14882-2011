#include <iostream>
using namespace std;

struct Distance    // Length in the English system.
{
    int feet;
    float inches;
};

Distance maxengl(Distance, Distance);
void engldisp(Distance);    // From RETSTRC.cpp (page 185).

int main()
{
    Distance d1, d2, dmax;

    cout << "\nEnter number of feet for d1: "; cin >> d1.feet;
    cout << "Enter number of inches for d1: "; cin >> d1.inches;

    cout << "\nEnter number of feet for d2: "; cin >> d2.feet;
    cout << "Enter number of inches for d2: "; cin >> d2.inches;

    dmax = maxengl(d1, d2);

    cout << "\nMax of ";
    engldisp(d1);
    cout << " and ";
    engldisp(d2);
    cout << " is ";
    engldisp(dmax);
    cout << endl;

    return 0;
}

//--------------------------------------------------------
// Returns the highest of two values of the "Distance" type.
Distance maxengl(Distance a, Distance b)
{
    double totalA = a.feet * 12.0 + a.inches;
    double totalB = b.feet * 12.0 + b.inches;

    if (totalA >= totalB)
        return a;
    else
        return b;
}

//--------------------------------------------------------
// Displays the fields of a structural variable with type "Distance".
void engldisp(Distance dd)
{
    cout << dd.feet << "\'-" << dd.inches << "\"";
}

// TODO:
// 1) Validate the "inches" field of both Distance variables to be in the range [0, 12) before calling maxengl().
// 2) Handle non-numeric input (e.g., letters or symbols) for both fields of struct variables.