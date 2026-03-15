// The program has already been modified in accordance with task 1.19.
//In addition, I used the "else if" combination to check several conditions in a row.
#include <iostream>
int main(){
    std::cout << "Enter the start and the end of any range:" << std::endl;
    int start = 0, end = 0;
    std::cin >> start >> end;
    if (start < end){
        std::cout << "List of numbers from " << start << " to " << end << " is:" << std::endl;
        while (start <= end){
            std::cout << start << std::endl;
            ++start;
        }
    }
    else if (start > end){
        std::cout << "List of numbers from " << end << " to " << start << " is:" << std::endl;
        while (end <= start){
            std::cout << end << std::endl;
            ++end;
        }
    }
    else {
        std::cout << "The number entered is equal. The range contains only one number: " << start << std::endl;
    }
    return 0;
}
