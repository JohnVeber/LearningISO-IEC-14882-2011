#include <iostream>
int main(){
    const float GALLONS_TO_CUBIC_FEET = 7.481f;
    std::cout << "Enter some number of gallons:" << std::endl;
    float gallons = 0.0f;
    float cubicFeets = 0.0f;
    std::cin >> gallons;
    cubicFeets = gallons * GALLONS_TO_CUBIC_FEET ;
    std::cout << "The equivalent volume in cubic feet is: " << cubicFeets << std::endl;
    return 0;
}