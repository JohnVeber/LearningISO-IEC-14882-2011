#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    unsigned long long N;
    
    if (argc > 1) {
        N = std::atoll(argv[1]);
    } else {
        std::cout << "Введите число: ";
        std::cin >> N;
    }
    
    auto sum_multiples = [](unsigned long long N, unsigned long long k) -> unsigned long long {
        unsigned long long m = N / k;
        return k * m * (m + 1) / 2;
    };
    
    unsigned long long sum = sum_multiples(N, 3) + sum_multiples(N, 5) - sum_multiples(N, 15);
    
    std::cout << "Сумма: " << sum << std::endl;
    return 0;
}