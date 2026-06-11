#include <iostream>
#include <cstdlib>  // для atoi

int main(int argc, char* argv[]) {
    unsigned int N;
    
    if (argc > 1) {
        N = std::atoi(argv[1]);  // берём N из командной строки
    } else {
        std::cout << "Введите число: ";
        std::cin >> N;
    }
    
    unsigned long long sum = 0;
    for (unsigned int i = 1; i <= N; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    
    std::cout << "Сумма: " << sum << std::endl;
    return 0;
}