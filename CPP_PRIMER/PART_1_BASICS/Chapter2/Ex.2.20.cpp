#include <iostream>

int main(){
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1; // Using this pointer the variable updated by a new value equal to a square of itself.
    std::cout << "Pointer value:  " << p1 << std::endl;
    std::cout << "Value of i:  " << *p1 << std::endl; // Expected result in this row is "Value of i:  1764".
    return 0;
}
