#include <iostream>
#include <cstdlib> // For labs() and exit().
using namespace std;

class Fraction {
private:
    int num;
    int den;
public:
    static constexpr char SEPARATOR = '/'; // Fraction separator.
    static constexpr char SPACE     = ' '; // Space used for padding.
    static constexpr char DASH      = '-'; // Separator line character.
    static constexpr char PIPE      = '|'; // Vertical separator in the final table.

    Fraction() : num(0), den(1) { } // Default constructor: initializes the fraction to 0/1.

    Fraction(int n, int d) : num(n), den(d) { // Parameterized constructor with validation of denominator.
        if (den == 0) {
            cout << "Error: denominator cannot be zero!" << endl;
            exit(1); // See TODO №1.
        }
        lowterms(); // Reducing a fraction automatically (if possible) during object creation.
    }

    // This is a "legacy" method from exercise 6.11; not actually used in this exercise (6.12),
    // but slightly improved: calls lowterms() after reading.
    void get() { // Method for reading a fraction from the user.
        char slash;
        while (true) {
            cout << "Enter a fraction in the format (numerator/denominator): ";
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
        lowterms(); // Reducing a fraction automatically (if possible) when changing object fields.
    }

    // This method was extended for the specific needs of the exercise:
    // it now accepts an optional field width, computes the length of the fraction,
    // and right-aligns the output within that field.
    // If width is 0 (the default), no alignment is performed and the fraction is printed as before.
    void display(int width = 0) const { // Constant method: prints the fraction to the screen.
        // Step 1: Compute the total length of the string "num/den"
        int len = 1; // Add one point for the '/' separator.
        int t = num; // Copy num to count its digits (num is const, so we use a copy).
        if (t == 0) { // Special case: the number 0 has one digit, but the loop below would skip it.
            len++;
        }
        while (t > 0) { // Count the remaining digits of the numerator.
            t /= 10;
            len++;
        }
        t = den; // Reuse t to count the digits of the denominator.
        // We still compute the length here, even though a zero denominator
        // would cause an error elsewhere (lowterms() checks for it).
        // This keeps the length calculation consistent and avoids surprises.
        if (t == 0) { // Same special case for the denominator.
            len++;
        }
        while (t > 0) { // Count the remaining digits of the denominator.
            t /= 10;
            len++;
        }

        // Step 2: Right-align the fraction within the field of given width.
        // Print (width - len) leading spaces.
        // If width == 0, the difference is negative and the loop does not execute, so no alignment occurs.
        for (int i = 0; i < width - len; i++) {
            cout << SPACE;
        }

        // Step 3: Print the fraction itself.
        cout << num << SEPARATOR << den;
    }

    // This method was not changed compared to Ex_6.11.
    void add(Fraction f1, Fraction f2) { // Method for adding two fractions.
        num = f1.num * f2.den + f2.num * f1.den;
        den = f1.den * f2.den;
        lowterms();
    }

    // This method was not changed compared to Ex_6.11.
    void sub(Fraction f1, Fraction f2) { // Method for subtracting two fractions.
        num = f1.num * f2.den - f2.num * f1.den;
        den = f1.den * f2.den;
        lowterms();
    }

    // This method was not changed compared to Ex_6.11.
    void mul(Fraction f1, Fraction f2) { // Method for multiplying two fractions.
        num = f1.num * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }

    // This method was not changed compared to Ex_6.11.
    void div(Fraction f1, Fraction f2) { // Method for dividing one fraction by another.
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

// This method was not changed compared to Ex_6.11. Only some comments were updated.
void Fraction::lowterms() { // Reduces the fraction to its simplest form.
    long tnum, tden, temp, gcd; // "gcd" means "greatest common divisor" of numerator and denominator.

    tnum = labs(num); // labs() returns the absolute value of a "long" argument.
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

    // Compute the column width:
    // This value is passed to display(),
    // which uses it to right-align the fraction within the field.
    int digitsInSquare = 0; // Number of digits in den*den (initialized to zero).
    int temp = den * den;   // Copy a square of den so that den itself is not modified.
    while (temp > 0) {      // Count digits one by one.
        temp /= 10;         // Drop the last digit.
        digitsInSquare++;   // Increment the digit counter.
    }
    // The formula below (twice the number of digits in den*den plus 3)
    // was chosen arbitrarily for readability of the table;
    // it is a matter of taste and can be changed if a different layout is preferred.
    int width = digitsInSquare * 2 + 3; // Field width: twice digits amount plus spaces and '/'.

    // Print the header row.
    // The first loop prints empty space above the left header column
    // so that the header aligns with the rows of table below.
    for (int i = 0; i < (width + 1); i++) {
        cout << Fraction::SPACE;
    }
    // The second loop prints each header fraction, separated by spaces.
    for (int n = 1; n < den; n++) {
        Fraction f(n, den);      // Construct the fraction n/den (reduced).
        cout << Fraction::SPACE; // Separator before the fraction.
        f.display(width);        // Print the fraction right-aligned.
        cout << Fraction::SPACE; // Separator after the fraction.
    }
    cout << endl;

    // Print the separator line.
    // The total length is:
    //   (width + 2)              — left header column, including space and a '|' before the table cells;
    //   (width + 2) * (den - 1)  — remaining (den - 1) columns.
    int separatorLength = width + 2 + (width + 2) * (den - 1);
    for (int i = 0; i < separatorLength; i++) {
        cout << Fraction::DASH;
    }
    cout << endl;

    // Print the multiplication table.
    // The outer loop iterates over the rows.
    // Each row corresponds to one fraction n1/den, which is used as the multiplier for that row.
    for (int n1 = 1; n1 < den; n1++) {
        // Row label: the fraction n1/den for this row.
        Fraction f1(n1, den);
        f1.display(width);
        cout << Fraction::SPACE << Fraction::PIPE;

        // Table cells: multiply the row fraction f1 by each column fraction f2.
        // The inner loop iterates over the columns (n2 = 1..den-1).
        for (int n2 = 1; n2 < den; n2++) {
            Fraction f2(n2, den); // Column fraction n2/den.
            Fraction result;
            result.mul(f1, f2);
            cout << Fraction::SPACE; // Separator before the cell.
            result.display(width);   // Print the result, right-aligned.
            cout << Fraction::SPACE; // Separator after the cell.
        }
        cout << endl;
    }

    return 0;
}

// TODO:
// 1) Using exit() in a constructor is bad practice (no stack unwinding). Rewrite without exit(), e.g. using exceptions.
// 2) Using exit() in lowterms() is also bad practice. Rewrite too.
// 3) Optimize algorithm in lowterms(): the current subtraction loop is slow. Consider using remainder (%) operation to reduce it to O(log n).