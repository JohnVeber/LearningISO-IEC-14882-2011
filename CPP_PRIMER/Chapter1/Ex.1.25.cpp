/* According to the book author's plan (see paragraph № 1 of topic 1.6), this program assumes
 that all transactions for each ISBN are entered by groups (sequentially).*/
#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item total;
    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn()){
                total += trans;
            }
            else{
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}