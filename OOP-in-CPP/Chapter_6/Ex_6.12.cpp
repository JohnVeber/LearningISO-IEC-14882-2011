#include <iostream>
#include <cstdlib> // For labs() and exit().
using namespace std;

class Fraction {
private:
    int num;
    int den;
    static constexpr char SEPARATOR = '/'; // Fraction separator.

public:
    Fraction() : num(0), den(1) { } // Default constructor: initializes the fraction to 0/1.

    Fraction(int n, int d) : num(n), den(d) { // Parameterized constructor with validation of denominator.
        if (den == 0) {
            cout << "Error: denominator cannot be zero!" << endl;
            exit(1); // See TODO №1.
        }
        lowterms();
    }

    // Method for reading a fraction from the user.
    void get() {
        char slash;
        while (true) {
            cout << "Enter a fraction (numerator/denominator): ";
            cin >> num >> slash >> den;
            if (!cin || slash != SEPARATOR) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: invalid format. Try again." << endl;
                continue;
            }
            if (den == 0) {
                cout << "Error: denominator cannot be zero. Try again." << endl;
                continue;
            }
            break;
        }
        lowterms();
    }

    // Constant method: prints the fraction to the screen.
    void display() const {
        cout << num << SEPARATOR << den;
    }

    // Method for adding two fractions.
    void add(Fraction f1, Fraction f2) {
        num = f1.num * f2.den + f2.num * f1.den;
        den = f1.den * f2.den;
        lowterms();
    }

    // Method for subtracting two fractions.
    void sub(Fraction f1, Fraction f2) {
        num = f1.num * f2.den - f2.num * f1.den;
        den = f1.den * f2.den;
        lowterms();
    }

    // Method for multiplying two fractions.
    void mul(Fraction f1, Fraction f2) {
        num = f1.num * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }

    // Method for dividing one fraction by another.
    void div(Fraction f1, Fraction f2) {
        if (f2.num == 0) {
            cout << "Error: division by zero!" << endl;
            exit(1); // See TODO №2.
        }
        num = f1.num * f2.den;
        den = f1.den * f2.num;
        lowterms();
    }

    void lowterms(); // Prototype of the method for reducing a fraction.
};

void Fraction::lowterms() { // Method for reducing a fraction to its lowest terms.
    long tnum, tden, temp, gcd; // gcd is "greatest common divisor" of numerator and denominator.

    tnum = labs(num); // labs() returns the absolute value of a long argument.
    tden = labs(den); // We take the absolute value of denominator too because Euclid's algorithm assumes operations on positive numbers.

    if (tden == 0) { // Division by zero handling.
        cout << "Invalid denominator!" << endl;
        exit(1); // See TODO №2.
    }
    else if (tnum == 0) { // In case numerator is zero — exit the method and set the fields to 0/1.
        num = 0;
        den = 1;
        return;
    }

    // Euclid's algorithm.
    while (tnum != 0) {
        if (tnum < tden) {
            temp = tnum;
            tnum = tden;
            tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;

    // Cast long result back to int to avoid implicit narrowing warnings.
    num = static_cast<int>(num / gcd);
    den = static_cast<int>(den / gcd);
}

int main() {
    int den;
    cout << "Enter the denominator (positive, greater than 1): ";
    cin >> den;
    if (!cin || den <= 1) {
        cout << "Error: denominator must be greater than 1." << endl;
        return 1;
    }

    // Print the header row.
    cout << "     ";
    for (int n = 1; n < den; n++) {
        Fraction f(n, den);
        cout << " "; f.display(); cout << " ";
    }
    cout << endl;

    // Print the separator line.
    for (int i = 0; i < 5 + (den - 1) * 6; i++) cout << "-";
    cout << endl;

    // Print the table.
    for (int n1 = 1; n1 < den; n1++) {
        Fraction f1(n1, den);
        f1.display(); cout << " |";
        for (int n2 = 1; n2 < den; n2++) {
            Fraction f2(n2, den);
            Fraction product;
            product.mul(f1, f2);
            cout << " "; product.display(); cout << " ";
        }
        cout << endl;
    }

    return 0;
}

// TODO:
// 1) Using exit() in a constructor is bad practice (no stack unwinding). Rewrite without exit(), e.g. using exceptions.
// 2) Using exit() in lowterms() is also bad practice. Rewrite too.
// 3) Optimize algorithm in lowterms(): the current subtraction loop is slow. Consider using remainder (%) operation to reduce it to O(log n).
// 4) Add a public method to Fraction to access numerator and denominator for duplicate checking and table alignment.