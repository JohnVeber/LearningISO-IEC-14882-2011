#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item item1, item2;
    // Read ISBN, number of books sold and price
    std::cin >> item1 >> item2; // Write two transactions
    // Print ISBN and number of books sold, total sum and average price
    std::cout << item1 + item2 << std::endl; // Print sum of objects
    return 0;
}
