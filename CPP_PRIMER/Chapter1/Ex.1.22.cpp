#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item result_item, item;
    if(std::cin >> item){
        result_item = item; // This step was necessary for ISBN initialization, as the operator "+=" did not copy it to the "result_item" object.
        while (std::cin >> item){
        result_item += item;
        }
        std::cout << "Sum of these transactions is:" << result_item << std::endl;
    }
    else{
        std::cout << "No data entered." << std::endl;
    }
    return 0;
}
