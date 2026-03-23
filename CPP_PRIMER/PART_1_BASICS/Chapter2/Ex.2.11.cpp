#include <iostream>

/*  Case a: */
extern int ix = 1024;       // This is definition
/*  Comments to the case a: */
// 1) Explicit initialization is permissible, but it invalidates the meaning of "extern".
// 2) Some compilers can provide a warning that "extern" is being ignored.


/*  Case b: */
int iy;                     // This is definition
/*  Comments to the case b: */
// 1) The variable is declared in the global scope without initialization.
// 2) The compiler allocates memory and performs zero-initialization (assigns 0).


/*  Case c: */
extern int iz;              // This is declaration
/*  Comments to the case c: */
// 1) There is a keyword "extern" and no initialization performed.
// 2) Memory is not allocated.

int main(){
    return 0;
}

/* ******************************************************* NOTES: ******************************************************* */

// Declaration (объявление) - informs the compiler about the existence of a name and its type, but does not allocate memory.
// Definition (определение) - highlights memory for a variable and can contain initialization.