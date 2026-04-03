/* Rows with invalid assignments are commented on. */
#include <iostream>

int main(){
    int i = 0;
    // Case a.
    // const int buf;

    // Case b.
    int cnt = 0;

    // Case c.
    const int sz = cnt;

    // Case d.
    ++cnt;
    // ++sz;

    std::cout << "cnt = " << cnt << std::endl; // Expected result in this row is "cnt = 1".
    std::cout << "sz = " << sz << std::endl; // Expected result in this row is "sz = 0".
}

/* **************************************************** COMMENTS: **************************************************** */

/* Case a: An uninitialized variable.*/

/* Case d2: Attempt to modify a constant object.*/