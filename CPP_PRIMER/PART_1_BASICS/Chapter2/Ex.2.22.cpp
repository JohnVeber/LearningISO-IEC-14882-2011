#include <iostream>

int main(){
    int i = 0;  // Depending on the value of this variable, the result in case b can be different.
    int *p = &i;
    // Case a.
    if(p){
        std::cout << "p != nullptr (the pointer is not null), p = " << p << std::endl;
    }
    else std::cout << "p = nullptr (but in this case the program will not compiled)" << std::endl;

    // Case b.
    if(*p){
        std::cout << "*p != 0 (object that p points to is not equal to zero), *p = " << *p << std::endl;
    }
    else std::cout << "*p = 0 (object that p points to is equal to zero), *p = " << *p << std::endl;
    return 0;
}
