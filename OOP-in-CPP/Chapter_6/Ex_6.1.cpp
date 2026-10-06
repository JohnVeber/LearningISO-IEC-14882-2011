#include <iostream>
using namespace std;

class Int {
private:
    int value;

public:
    Int() : value(0) { } // Default constructor: initializes value to zero.

    Int(int v) : value(v) { } // Parameterized constructor.

    // Method for setting the value from input.
    void setvalue() {
        cout << "Enter the value: ";
        cin >> value;
    }

    // Method for printing the value to the screen.
    void printvalue() const {
        cout << "The value of the field is: " << value << endl;
    }

    // Method that sums two "Int" objects.
    void sumvalues(Int n1, Int n2) {
        value = n1.value + n2.value;
    }
};

int main() {
    Int i1(0);
    cout << "First object: "; // Display the value of the first object.
    i1.printvalue();

    Int i2;
    i2.setvalue();
    cout << "Second object: "; // Display the value of the second object.
    i2.printvalue();

    Int i3;
    i3.sumvalues(i1, i2);

    cout << "Result of summation: "; // Display the result.
    i3.printvalue();

    return 0;
}
