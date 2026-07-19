/* Rows with invalid assignments are commented on. */
#include <iostream>
#include <iomanip>   // For std::fixed and std::setprecision() usage (row 19)

int i = 0, &r1 = i;
double d = 0, &r2 = d;


int main(){
    r2 = 3.14159;    // Result: d = 3.14159, i = 0
    r2 = r1;         // Result: d = 0.0, i = 0
    i = r2;          // Result: i = 0, d = 0.0
    r1 = d;          // Result: i = 0, d = 0.0

    // These rows just to check output:
    std::cout << "i = " << i << std::endl;
    std::cout << "d = " << d << std::endl;
    // The real output ;)
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    return 0;
}
