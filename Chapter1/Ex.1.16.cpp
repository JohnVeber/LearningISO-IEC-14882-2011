// My example of a simple program that sums an arbitrary quantity of numbers from the standard input.
#include <iostream>
int main(){
    std::cout << "Enter some numbers:" << std::endl;
    int v = 0, sum = 0;
    while (std::cin >> v){
        sum += v;
    }
    std::cout << "Sum of these numbers is:" << sum << std::endl;
    return 0;
}
