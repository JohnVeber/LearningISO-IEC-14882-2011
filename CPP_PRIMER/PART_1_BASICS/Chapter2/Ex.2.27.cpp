/* Rows with unacceptable initializations are commented on. */
#include <iostream>

int main(){
    // Case a.
    // int i = -1, &r = 0;

    // Case b.
    int i2 = 42;  // We need to initialise i2 first
    int *const p2 = &i2;
    // Just to check output:
    std::cout << "i2 = " << i2 << std::endl;
    std::cout << "*p2 = " << *p2 << std::endl;

    // Case c.
    const int i = -1;
    const int &r = 0; // Possible, because the reference is a constant
    std::cout << "i = " << i << std::endl;
    std::cout << "r = " << r << std::endl;

    // Case d.
    i2 = 44;   // Just to refresh it
    const int *const p3 = &i2;    // Initializing a constant pointer to a constant type by an address of a non-constant variable.
    std::cout << "i2 = " << i2 << std::endl;
    std::cout << "*p3 = " << *p3 << std::endl;

    // Case e.
    i2 = 46;   // Just to refresh it
    const int *p1 = &i2;
    std::cout << "i2 = " << i2 << std::endl;
    std::cout << "*p1 = " << *p1 << std::endl;

    // Case f.
    //const int &const r;

    // Case g.
    // Name of variables were changed just to combine all cases in one program.
    int b = 10;
    const int b2 = b;    // Initializing a constant object by a value of non-constant one.
    const int &rg = b;   // Binding a const reference to a non-const object.

    std::cout << "b = " << b << std::endl;
    std::cout << "b2 = " << b2 << std::endl;
    std::cout << "rg = " << rg << std::endl;

    return 0;
}

/* **************************************************** COMMENTS: **************************************************** */

/* Case a: An attempt to bind the non-constant reference to a literal. */

/* Case c: Compiler will create a temporary object with type of int and put the value "0" inside them. */

/* Case f: References do not have a separate term like "reference constancy". Reference cannot be qualified as "const" */
