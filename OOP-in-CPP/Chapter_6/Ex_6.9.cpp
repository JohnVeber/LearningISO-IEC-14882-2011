#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
        static constexpr char SEPARATOR = '/';
    public:
        Fraction() : numerator(0), denominator(1) { } // Default constructor: initializes the fraction to 0/1.

        void getFraction() {
            char slash; // For separator validation.
            while (true) {
                cout << "enter fraction in a/b format: ";
                cin >> numerator >> slash >> denominator;
                if (!cin || slash != SEPARATOR) {
                    cin.clear();             // Reset the error flag on cin.
                    cin.ignore(10000, '\n'); // Discard the invalid input.
                    cout << "Error: invalid format. Try again." << endl;
                    continue;
                }

                if (denominator == 0) { // Compare denominator to zero.
                    cout << "Error: division by zero forbidden. Try again." << endl;
                    continue;
                }
                break; // All checks passed.
            }
        }

        void printFraction() const {
            cout << numerator << SEPARATOR << denominator <<  endl;
        }

        void addFraction(Fraction f1, Fraction f2);
};

void Fraction::addFraction(Fraction f1, Fraction f2){
    numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    denominator = f1.denominator * f2.denominator;

}

int main() {
    char yesNo = 0;
    do {
        Fraction frac1;
        cout << "\nFirst fraction: ";
        frac1.getFraction();
        Fraction frac2;
        cout << "\nSecond fraction: ";
        frac2.getFraction();
        Fraction frac3;
        frac3.addFraction(frac1, frac2);
        cout << "\nThe sum of two fractions is: ";
        frac3.printFraction();
        cout << "\nDo you want to sum the next two fractions? (y/n): ";
        cin >> yesNo;
        cin.ignore(10000, '\n'); // Discard any leftover characters after the answer.
    } while (yesNo == 'y' || yesNo == 'Y');

    return 0;
}

// TODO:
// 1) Implement fraction reduction (simplification) using the greatest common divisor.