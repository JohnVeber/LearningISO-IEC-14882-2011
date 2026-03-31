#include <iostream>

int main(){
    // Case a : Change pointer value.
    int ival, *p1 = nullptr;
    std::cout << "Initial value:  " << p1 << std::endl;
    ival = 5;
    p1 = &ival;
    std::cout << "New value:  " << p1 << std::endl;

    // Case b: Change the value indicated by pointer.
    std::cout << "1st value:  " << *p1 << std::endl;
    int ival2 = 1000;
    *p1 = ival2;
    std::cout << "2nd value:  " << *p1 << std::endl;
    int ival3 = 888;
    p1 = &ival3;
    std::cout << "3rd value:  " << *p1 << std::endl;
    return 0;
}
