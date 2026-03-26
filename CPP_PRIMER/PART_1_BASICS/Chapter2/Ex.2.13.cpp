#include <iostream>

int i = 42;     // Global variable i
int main(){
    int i =100; // Local variable i
    int j = i;  // Inside the main() function , the name "i" refers to a local variable, not a global one.
    std::cout << j << std:: endl;
    return 0;
}
