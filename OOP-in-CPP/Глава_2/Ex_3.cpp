#include <iostream>
using namespace std;
int main(){
    const int VAR = 10;
    int res = VAR;
    cout << VAR << endl;
    res += VAR;
    cout << res << endl
    << --res << endl;
}