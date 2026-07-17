#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    long pop1 = 8425785, pop2 =47, pop3 = 9761;
    cout << left << setw(9) << "City" << right << setw(12) << "Population" << endl
    << left << setfill('.') << setw(9) << "Moscow" << right << setw(12) << pop1 << endl
    << left << setfill('.') << setw(9) << "Kirov" << right << setw(12) << pop2 << endl
    << left << setfill('.') << setw(9) << "Ugrymovka" << right << setw(12) << pop3 << endl;
    return 0;
}

// The expected output is:
// City       Population
// Moscow........8425785
// Kirov..............47
// Ugrymovka........9761