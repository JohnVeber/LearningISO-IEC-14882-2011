/* Rows with invalid definitions are commented on. */
#include <iostream>

int main(){
    // Case a.
    // int i, *const cp;  // Error: constant pointer cp is not initialized.

    // Case b.
    // int *p1, *const p2;  // Error: constant pointer p2 is not initialized.

    // Case c.
    // const int ic, &r = ic;  // Error: const object "ic" is not initialized.

    // Case d.
    // const int *const p3;  // Error: constant pointer p3 is not initialized.

    // Case e.
    const int *p;  // OK. Pointer to const (non const pointer) can be defined without initialization.

    return 0;
}

/* **************************************************** COMMENTS: **************************************************** */

/* Case c: The reference &r = ic would be valid if ic were initialized */
