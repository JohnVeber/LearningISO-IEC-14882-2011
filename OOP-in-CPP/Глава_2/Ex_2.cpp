#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int var = 1990;
    cout << setw(4) << var << setw(9) << 135 << endl
    << setw(4) << ++var << setw(9) << 7290 << endl
    << setw(4) << ++var << setw(9) << 11300 << endl
    << setw(4) << ++var << setw(9) << 16200 << endl;
}