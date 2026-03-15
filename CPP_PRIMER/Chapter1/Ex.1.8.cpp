/* As the compillation result we will get the next warning: "missing terminating ' character" */
#include <iostream>
int main(){
    // Example 1
    std::cout << "/*";
    // Example 1 (fixed)
    /* No changes needed.*/

    // Example 2
    std::cout << "*/";
    // Example 2 (fixed)
    /* No changes needed.*/

    // Example 3
    //std::cout << /*	"*/" */;
    // Example 3 (fixed)
    std::cout << /*	"*/" */";

    // Example 4
    std::cout << /*	"*/" /*	"/*" */;
    // Example 4 (fixed)
    /* No changes needed.*/
    return 0;
}
