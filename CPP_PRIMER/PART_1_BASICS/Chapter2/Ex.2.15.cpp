/* Rows with unacceptable definitions are commented on. */
#include <iostream>

int ival = 1.01; // The conversion is acceptable (but not recommended).

// It is unacceptable: The non-constant reference (int&) requires l-value - an object with an address in memory.
// int &rval1 = 1.01;

int &rval2 = ival;

// It is unacceptable: the variable declared as reference but not initialized.
// int &rval3;

int main(){
    return 0;
}
