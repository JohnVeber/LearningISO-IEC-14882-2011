/* According to the book author's plan (see task № 1.24), this program assumes
 that all transactions for each ISBN are entered by groups (sequentially).*/
#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item current_item, next_item;
    int amount = 1;
    if(std::cin >> current_item){
        while(std::cin >> next_item){
            if(current_item.isbn() == next_item.isbn()){
                ++amount;
            }
            else{
                std::cout << "ISBN " << current_item.isbn() << " occurs " << amount << " times." << std::endl;
                current_item = next_item;
                amount = 1;
            }
        }
        std::cout << "ISBN " << current_item.isbn() << " occurs " << amount << " times." << std::endl;
        return 0;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
}