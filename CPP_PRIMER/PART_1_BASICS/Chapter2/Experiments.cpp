/* Служебная программа для проверки предположений в ходе выполнения задач. */
/* Код в этом файле не является корректным ! */

#include <iostream>

std::string global_str;
int global_int;

int main(){
    // Хитрость: создаем мусор в отдельной функции
    // Это заставляет компилятор реально записать данные в стек
    []() {
        volatile int garbage[1000];
        for (int i = 0; i < 1000; ++i) {
            garbage[i] = i * 12345 + 6789;
        }
        // volatile заставляет компилятор реально выполнить запись
        std::cout << "Garbage created, last value: " << garbage[999] << std::endl;
    }();  // немедленный вызов лямбды

    // Теперь local_int объявляется после того, как лямбда завершилась
    // и её кадр стека уничтожен. При определенных обстоятельствах
    // компилятор может переиспользовать ту же память.
    int local_int;

    // Барьер памяти — запрещаем компилятору оптимизировать порядок
    asm volatile("" : : : "memory");

    std::string local_str;

    std::cout << "Case 1) global_string: from" << global_str << "to" << std::endl;
    std::cout << "Case 2) global_int: " << global_int << std::endl;
    std::cout << "Case 3) local_string: from" << local_str << "to" << std::endl;
    std::cout << "Case 4) local_int: " << local_int << std::endl;
    return 0;
}