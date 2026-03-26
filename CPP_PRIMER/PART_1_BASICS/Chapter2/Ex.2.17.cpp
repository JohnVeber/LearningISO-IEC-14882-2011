#include <iostream>

int main(){
    int i = 0, &ri = i;
    i = 5;
    ri = 10;            // Assignment "ri = 10" is equivalent of "i = 10"
    std::cout << i << " " << ri << std:: endl;
    return 0;
}
