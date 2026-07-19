/* Rows with variables which have unacceptable names are commented on. */
#include <iostream>

// It is unacceptable: keyword is used.
// int double = 3.14;

int _; // acceptable

// It is unacceptable: a prohibited character "-" is used.
// int catch-22;

// It is unacceptable: name can’t start with a number.
// int 1_or_2 = 1;

double Double = 3.14; // acceptable

int main(){
    return 0;
}
