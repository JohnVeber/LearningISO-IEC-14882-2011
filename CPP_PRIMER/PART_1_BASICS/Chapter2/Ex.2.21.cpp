/* Rows with invalid assignments are commented on. */
#include <iostream>

int main(){
    int i = 0;
    // Case a.
    //double* dp = &i;

    // Case b.
    //int *ip = i;

    // Case c.
    int *p = &i;

    std::cout << "Value of *p is:  " << *p << std::endl; // Expected result in this row is "Value of *p is:  "0".
    return 0;
}

/* **************************************************** COMMENTS: **************************************************** */

/* Case a: We can’t initialize the pointer of one type by a value of the variable with another type
 without explicit conversion (reinterpret_cast).*/

/* Case b: The pointer must be initialized by an address, not a value.
The exception is only a literal "0" (or nullptr) that can be assigned to a pointer.*/

/* Case c: Correct.*/