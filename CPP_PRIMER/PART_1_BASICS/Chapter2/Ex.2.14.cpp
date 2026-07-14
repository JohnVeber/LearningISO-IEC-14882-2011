#include <iostream>

int main(){
    int i = 100 ,sum = 0;                          // This variable "i" exists but is not used within the cycle.
    for(int i = 0; i != 10; ++i){                  // The external variable "i = 100" is hidden within the loop by the local one with the same name.
        sum += i;                                  // The "sum" variable is declared once and available everywhere.
        std::cout << i << " " << sum << std:: endl;
    }
    return 0;
}
