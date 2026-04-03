/* Служебная программа для проверки предположений в ходе выполнения задач. */
/* Код в этом файле не является корректным !                               */

#include <iostream>

// Определение функции до её использования
int get_size() {
    return 3 - 3;   // должно быть return, а не просто выражение
}

int main() {
    const int bufSize = get_size();  // ✅ теперь компилятор знает о функции
    std::cout << "bufSize = " << bufSize << std::endl;
    if (bufSize){
        std::cout << "bufSize !=0  : " << bufSize << std::endl;
    }
    else std::cout << "bufSize=0  : " << bufSize << std::endl;
    return 0;
}