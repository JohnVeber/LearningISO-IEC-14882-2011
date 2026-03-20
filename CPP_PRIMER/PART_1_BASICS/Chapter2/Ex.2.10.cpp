/* Some additional comments and conclusions added to the original listing. */
#include <iostream>

std::string	global_str;
int	global_int;

int main(){
    int	local_int;
    std::string	local_str;

    std::cout << "Case 1) global_string: " << "from" << global_str << "to" << std::endl;    // OK: The result of zero-initialization. We see no characters inside this string.
    std::cout << "Case 2) global_int: " << global_int << std::endl;                         // OK: Again zero-initialization cause the variable isn't defined in function body.
    std::cout << "Case 3) local_string: " << "from" << local_str << "to" << std::endl;      // OK: Objects of type "class" defined in the function body are initialized by default.
    std::cout << "Case 4) local_int: " << local_int << std::endl;                           // UB: Reading an uninitialized local variable of built-in type (like int) results in undefined behavior.
    return 0;
}

/* *********************************************** The expected output is: ********************************************** */

// Case 1) global_string: fromto
// Case 2) global_int: 0
// Case 3) local_string: fromto
// Case 4) local_int: 0


/* **************************************************** CONCLUSIONS: **************************************************** */

// 1. Global variables never contain "garbage."
// 2. The g++ compiler intentionally resets uninitialized local variables in certain situations (Case 4) !!!
// 3. In Case 4, the g++ compiler exhibits a specific implementation behavior — it intentionally resets such variables to zero in certain situations, though the compiler is not required to preserve any particular value. !!!
// 4. The C++ standard permits the compiler to produce any result when UB occurs, including 0, garbage, or program crashes .
// 5. Attempting to demonstrate "garbage" values reliably is difficult because the compiler is not required to preserve them.