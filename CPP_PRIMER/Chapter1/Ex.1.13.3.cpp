#include <iostream>
int main(){
    std::cout << "Enter the start and the end of any range:" << std::endl;
    int start = 0, end = 0;
    std::cin >> start >> end;
    
    if (start < end){
        std::cout << "List of numbers from " << start << " to " << end << " is:" << std::endl;
        for (int current = start; current <= end; ++current){
        std::cout << current << std::endl;
        }
    }
    else if (start > end){
        std::cout << "List of numbers from " << end << " to " << start << " is:" << std::endl;
        for (int current = end; current <= start; ++current){
        std::cout << current << std::endl;
        }
    }
    else {
        std::cout << "The number entered is equal. The range contains only one number: " << start << std::endl;
    }
    return 0;
}
