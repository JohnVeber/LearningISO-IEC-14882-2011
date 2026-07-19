#include <iostream>
using namespace std;
int main(){
    int a, b, c, d;
    char slash;
    cout << "Enter the first fraction in a/b format: ";
    cin >> a >> slash >> b;
    if (slash != '/') {
        cout << "ERROR: incorrect format or unrecognized value." << endl;
        return 1;
    }
    if (b == 0) {
        cout << "ERROR: Denominator cannot be zero." << endl;
        return 1;
    }
    cout << "Enter the second fraction in the same format: ";
    cin >> c >> slash >> d;
    if (slash != '/') {
        cout << "ERROR: incorrect format or unrecognized value." << endl;
        return 1;
    }
    if (d == 0) {
        cout << "ERROR: Denominator cannot be zero." << endl;
        return 1;
    }
    int numerator = a * d + b * c;
    int denominator = b * d;
    cout << "The sum of fractions is: " << numerator << "/" << denominator << endl;
    return 0;
}