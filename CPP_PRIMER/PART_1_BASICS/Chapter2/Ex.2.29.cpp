/* Rows with unacceptable initializations are commented on. */
#include <iostream>

int main(){
    // Case a.
    int i = -1;                    // From 2.27(a)
    const int ic = 20;             // From 2.27(c) (initialization added).
    i = ic;                        // Assignment of case a.
    std::cout << "Case a: "<< std::endl;
    std::cout << "i = " << i << std::endl;
    std::cout << "ic = " << ic << std::endl;

    // Case b.
    const int i2 = i;              // From 2.27(g) Initializing a constant just to initialize p1 at the nex row.
    const int *p1 = &i2;           // From 2.27(e)
    const int *const p3 = &i2;     // From 2.27(d)
    p1 = p3;                       // Assignment of case b.
    std::cout << "Case b: "<< std::endl;
    std::cout << "*p1 = " << *p1 << std::endl;
    std::cout << "*p3 = " << *p3 << std::endl;

    // Case c.
    p1 = &ic;                      // Assignment of case c.
    std::cout << "Case c: "<< std::endl;
    std::cout << "*p1 = " << *p1 << std::endl;
    std::cout << "ic = " << ic << std::endl;

    // Case d.
    //p3 = &ic;                    // Assignment of case d.

    // Case e.
    //int *const p2 = &i2;         // From 2.27(e) - But it's incorrect initialisation because of the row 14.
    int *const p2 = &i;            // That's why we use a correct type here.
    // p2 = p1;                    // Assignment of case e.

    // Case f.
    // ic = *p3;                   // Assignment of case f.

    return 0;
}

/* **************************************************** COMMENTS: **************************************************** */

/* Case c: Non-constant pointer "p1" itself can be redirected (to another object with the same type: i2 --> ic). */

/* Case d: A constant pointer "p3" itself can't be redirected.  */

/* Case e: A constant pointer "p2" itself can't be redirected.  */

/* Case f: Constant "ic" cannot be changed after initialization.  */



/* ****************** Expected output is:

Case a:
i = 20
ic = 20
Case b:
*p1 = 20
*p3 = 20
Case c:
*p1 = 20
ic = 20

******************************************/
