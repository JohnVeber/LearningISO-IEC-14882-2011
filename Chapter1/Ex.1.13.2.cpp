#include <iostream>
int main(){
    std::cout << "List of numbers from 10 to 0: " << std::endl;
    for (int val = 10; val >= 0; --val){
        std::cout << val << std::endl;
    }
    return 0;
}
