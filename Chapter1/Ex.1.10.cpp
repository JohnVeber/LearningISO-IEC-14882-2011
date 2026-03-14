#include <iostream>
int main(){
    int val = 10;
    std::cout << "List of numbers from 10 to 0: " << std::endl;
    while (val >= 0){
        std::cout << val << std::endl;
        --val;
    }
    return 0;
}