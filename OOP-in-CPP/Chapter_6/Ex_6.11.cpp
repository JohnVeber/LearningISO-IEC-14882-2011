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
    }

    // Constant method: prints the fraction to the screen.
    void display() const {
        cout << num << SEPARATOR << den << endl;
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

    void lowterms(); // Prototype of the method for reducing the fraction.
};


void Fraction::lowterms() { // Method for reducing the fraction to its lowest terms.
    long tnum, tden, temp, gcd;

    tnum = labs(num);
    tden = labs(den);

    if (tden == 0) {
        cout << "Invalid denominator!" << endl;
        exit(1); // See TODO №2.
    } else if (tnum == 0) {
        num = 0; den = 1; return;
    }

    // Euclid's algorithm.
    while (tnum != 0) {
        if (tnum < tden) {
            temp = tnum; tnum = tden; tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;

    // Cast long result back to int to avoid implicit narrowing warnings.
    num = static_cast<int>(num / gcd);
    den = static_cast<int>(den / gcd);
}

int main() {
    Fraction fr1, fr2, fr3;
    char operation;
    char ch;

    do {
        fr1.get();
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        fr2.get();

        switch (operation) {
            case '+':
                fr3.add(fr1, fr2); cout << "Result: "; fr3.display(); break;
            case '-':
                fr3.sub(fr1, fr2); cout << "Result: "; fr3.display(); break;
            case '*':
                fr3.mul(fr1, fr2); cout << "Result: "; fr3.display(); break;
            case '/':
                fr3.div(fr1, fr2); cout << "Result: "; fr3.display(); break;
            default:
                cout << "Invalid operation! Try again." << endl;
                continue; // Skip the rest of the loop and request input again.
        }

        // Validate an answer: only 'y', 'Y', 'n', 'N' are allowed.
        while (true) {
            cout << "Perform another operation (y/n)? ";
            cin >> ch;
            if (!cin || (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Error: please enter 'y' or 'n'." << endl;
                continue;
            }
            cin.ignore(10000, '\n');
            break;
        }
    } while (ch == 'y' || ch == 'Y');

    return 0;
}

// TODO:
// 1) Using exit() in a constructor is bad practice (no stack unwinding). Rewrite without exit(), e.g. using exceptions.
// 2) Using exit() in lowterms() is also bad practice. Rewrite too.