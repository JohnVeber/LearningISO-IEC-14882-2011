/* Служебная программа для проверки предположений в ходе выполнения задач. */
/* Код в этом файле не является корректным !                               */

#include <iostream>
int main(){
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd;
    std::cout << *static_cast<double*>(pv) << "          " << *pd;
    return 0;
}
